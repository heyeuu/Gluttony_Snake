
#include "snake.hpp"
#include <cstddef>
#include <exception>
#include <ncurses.h>
#include <vector>

struct Position {
    int x, y;
};

Snake::Snake(std::vector<Position> initial_body)
    : direction_{Direction::UP}, body_{std::move(initial_body)} {
    // explicit
    // std::move
}

void Snake::set_direction(Direction direction) {
    if (direction == Direction::UP && direction_ == Direction::DOWN)
        return;
    if (direction == Direction::DOWN && direction_ == Direction::UP)
        return;
    if (direction == Direction::LEFT && direction_ == Direction::RIGHT)
        return;
    if (direction == Direction::RIGHT && direction_ == Direction::LEFT)
        return;

    direction_ = direction;
}

Snake::Position Snake::forward_head() {
    constexpr Position direction_to_move[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // auto [offset_x, offset_y] =
    // direction_to_move[static_cast<int>(direction_)];

    auto offset = direction_to_move[static_cast<int>(direction_)];

    Position new_head = {body_[0].x + offset.x, body_[0].y + offset.y};

    body_.insert(body_.cbegin(), new_head);

    return new_head;
}
Snake::Position Snake::head() { return {body_[0].x, body_[0].y}; }

bool Snake::in_self(Position position) const {
    for (auto &body : body_) {
        if (body.x == position.x && body.y == position.y)
            return true;
    }
    return false;
}

bool Snake::in_self_without_head(Position position) const {
    for (size_t i = 1; i < body_.size(); i++) {
        if (body_[i].x == position.x && body_[i].y == position.y)
            return true;
    }
    return false;
}

void Snake::forward_tail() { body_.pop_back(); }

void Snake::render(int color) const {
    attron(COLOR_PAIR(color));
    for (auto &body : body_) {
        mvaddch(body.x, body.y * 2, ' ');
        mvaddch(body.x, body.y * 2 + 1, ' ');
    }
    attroff(COLOR_PAIR(color));
}

const std::vector<Snake::Position> &Snake::body() const { return body_; }
