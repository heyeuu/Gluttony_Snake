
#include "snake.hpp"

#include <cstddef>
#include <exception>
#include <functional>
#include <iterator>
#include <ncurses.h>
#include <queue>
#include <unordered_set>
#include <vector>

struct Position {
    int x, y;
};

Snake::Snake(std::vector<Position> initial_body)
    : direction_{Direction::UP},
      next_direction_{Direction::UP}, body_{std::move(initial_body)} {
    // explicit
    // std::move
}

void Snake::set_direction(Direction direction) { next_direction_ = direction; }
void Snake::apply_direction() {
    if (next_direction_ == Direction::UP && direction_ == Direction::DOWN)
        return;
    if (next_direction_ == Direction::DOWN && direction_ == Direction::UP)
        return;
    if (next_direction_ == Direction::LEFT && direction_ == Direction::RIGHT)
        return;
    if (next_direction_ == Direction::RIGHT && direction_ == Direction::LEFT)
        return;
    direction_ = next_direction_;
}
Snake::Position Snake::forward_head() {
    // constexpr Position direction_to_move[] = {{-1, 0}, {1, 0}, {0, -1}, {0,
    // 1}};

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

size_t Ai_snake::get_snake_size() { return get_body_size() + 1; }
Ai_snake::Position Ai_snake::forward_head() {
    auto head = Snake::head();
    auto dir_x = a_star.path_.front().x - head.x;
    auto dir_y = a_star.path_.front().y - head.y;
    for (size_t i = 0; i < a_star.offset.size(); i++) {
        if (dir_x == a_star.offset[i].dx && dir_y == a_star.offset[i].dy) {

            Position new_head = {body_[0].x + dir_x, body_[0].y + dir_y};
            body_.insert(body_.cbegin(), new_head);
            return new_head;
        }
    }
}