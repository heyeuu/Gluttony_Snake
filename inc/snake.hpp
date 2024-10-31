#pragma once

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

    bool in_self(Position position) const;

    bool in_self_without_head(Position position) const;

    void forward_tail();

    void render(int color) const;

    const std::vector<Position> &body() const;

private:
    Direction direction_, next_direction_;

    std::vector<Position> body_;
};