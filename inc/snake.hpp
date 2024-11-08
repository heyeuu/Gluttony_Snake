#pragma once

#include <cstddef>
#include <exception>
#include <ncurses.h>
#include <vector>

class Snake {
public:
    enum class Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
    struct Position {
        int x, y;
    };

    Snake(std::vector<Position> initial_body);

    void set_direction(Direction direction);
    void apply_direction();
    Position forward_head();
    Position head();
    size_t get_body_size() { return body_.size(); }

    bool in_self(Position position) const;

    bool in_self_without_head(Position position) const;

    void forward_tail();

    void render(int color) const;

    const std::vector<Position> &body() const;

protected:
    Direction direction_, next_direction_;
    const Position direction_to_move[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector<Position> body_;

private:
};
class A_star {
public:
    using Position = Snake::Position;
    struct Node {
        using Position = Snake::Position;
        int g{0}, h{0}, f{g + h};
        Position pos{10, 10};
        Node *parent{nullptr};
    };
    // Node 初始化待优化

    void search(Node);

    struct compare {
        bool operator()(const Node &a, const Node &b) { return a.f > b.f; }
    };
    std::priority_queue<Node, std::vector<Node>, compare> open_list_;
    std::vector<Position> closed_list_;
    std::queue<Position> path_;

    struct delta {
        int dx{0}, dy{0};
    };
    const std::vector<delta> offset{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

protected:
private:
    /////加&?
    int set_node_h(Node &node, Position endpos);
    void set_node_g(Node &node);
    int set_node_f(Node &node);

    bool in_closed_list(Position);

    Node *creat_neighbor_node(Position endpos, delta offset, Node *par);

    std::vector<Node> neighbor_nodes_;
};

class Ai_snake : public Snake {
public:
    size_t get_snake_size();
    Position forward_head();
    A_star a_star;
};