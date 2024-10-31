#include "game.hpp"
#include "snake.hpp"
#include <chrono>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <curses.h>
#include <exception>
#include <iostream>
#include <iterator>
#include <ratio>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

Game::Game() : mode_opt_(0) {
    srand(std::time(0));
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    napms(100);
    timeout(1000);
    game_over_ = false;
}

void Game::run() {
    // std::thread timer_thread(&Game::mytimer, this);
    while (!game_over_) {

        render();

        if (game_over_) {
            render();
            // keep_running_ = false;
            break;
        }

        parse_input();

        step();
    }
    // timer_thread.join();
}

void Game::generate_food() {
    bool available;
    do {
        available = true;
        food_.x = rand() % (height - 2) + 1;
        food_.y = rand() % (width - 2) + 1;
        for (const auto &snake : snakes_) {
            if (snake.in_self(food_)) {
                available = false;
                break;
            }
        }
    } while (!available);
}

void Game::parse_input() {
    auto start = std::chrono::steady_clock::now();
    while (true) {
        int time_left = 300 - std::chrono::round<std::chrono::milliseconds>(
                                  std::chrono::steady_clock::now() - start)
                                  .count();
        if (time_left <= 0)
            break;

        timeout(time_left);
        int input = getch();
        if (input == ERR)
            break;

        switch (input) {

        case KEY_UP:
            snakes_.at(0).set_direction(Snake::Direction::UP);
            break;
        case KEY_DOWN:
            snakes_.at(0).set_direction(Snake::Direction::DOWN);
            break;
        case KEY_LEFT:
            snakes_.at(0).set_direction(Snake::Direction::LEFT);
            break;
        case KEY_RIGHT:
            snakes_.at(0).set_direction(Snake::Direction::RIGHT);
            break;

        case 'w':
            if (snakes_.size() == 2) {
                snakes_.at(1).set_direction(Snake::Direction::UP);
            }
            break;

        case 's':
            if (snakes_.size() == 2) {
                snakes_.at(1).set_direction(Snake::Direction::DOWN);
            }
            break;

        case 'a':
            if (snakes_.size() == 2) {
                snakes_.at(1).set_direction(Snake::Direction::LEFT);
            }
            break;

        case 'd':
            if (snakes_.size() == 2) {
                snakes_.at(1).set_direction(Snake::Direction::RIGHT);
            }
            break;

        default:;
        }
    }
    for (size_t i = 0; i < snakes_.size(); i++)
        snakes_[i].apply_direction();
}

void Game::step() {
    for (size_t i = 0; i < snakes_.size(); i++) {
        auto &snake = snakes_[i];
        auto position = snake.forward_head();

        if (position.x == food_.x && position.y == food_.y) {
            generate_food();
        } else {
            snake.forward_tail();
        }

        if (position.x == 0 || position.x == height - 1 || position.y == 0 ||
            position.y == width - 1) {
            collision_point_.push_back(position);

            game_over_ = true;
        } else if (snake.in_self_without_head(position)) {

            collision_point_.push_back(position);
            game_over_ = true;
        }
    }

    for (size_t i = 0; i < snakes_.size(); i++) {
        auto &snake = snakes_[i];
        auto position = snake.head();
        for (size_t j = 0; j < snakes_.size(); ++j) {
            if (i == j)
                continue;
            auto &other_snake = snakes_[j];
            if (other_snake.in_self(position)) {
                collision_point_.push_back(position);

                game_over_ = true;
                return;
            }
        }
    }
    refresh();
}

void Game::render() {
    clear();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);     // 边界
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW);   // 蛇1P
    init_pair(3, COLOR_BLUE, COLOR_BLUE);       // 蛇2P
    init_pair(6, COLOR_RED, COLOR_RED);         // 食物
    init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA); //游戏结束原因点
    init_pair(4, COLOR_CYAN, COLOR_CYAN);       //皮肤3
    init_pair(5, COLOR_GREEN, COLOR_GREEN);     //皮肤4
    init_pair(8, COLOR_BLACK, COLOR_BLACK);

    if (mode_opt_ != 2) {
        attron(COLOR_PAIR(1));
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height * 2 - 1; y += 2) {
                if (y == 0 || (y == (height * 2 - 2)) || (x == 0) ||
                    x == (width - 1)) {
                    mvaddch(x, y, ' ');
                    mvaddch(x, y + 1, ' ');
                }
            }
        }
        attroff(COLOR_PAIR(1));

        for (size_t i = 0; i < snakes_.size(); i++) {
            snakes_[i].render(2 + style_opt[i]);
        }

        attron(COLOR_PAIR(6));
        mvaddch(food_.x, food_.y * 2, ' ');
        mvaddch(food_.x, food_.y * 2 + 1, ' ');
        attroff(COLOR_PAIR(6));

        attron(COLOR_PAIR(7));
        for (size_t i = 0; i < collision_point_.size(); i++) {
            mvaddch(collision_point_[i].x, collision_point_[i].y * 2, ' ');
            mvaddch(collision_point_[i].x, collision_point_[i].y * 2 + 1, ' ');
        }
        attroff(COLOR_PAIR(7));
        refresh();
    }
}

void Game::render_menu() {

    int ch = ' ';
    do {
        clear();
        mvprintw(0, 0, "Please choose an option:");
        mvprintw(1, 0, "    MENU");
        for (int i = 0; i < 3; i++) {
            if (i == mode_opt_)
                attron(A_REVERSE);
            mvprintw(i + 2, 0, "%s", menu_choice[i]);
            if (i == mode_opt_)
                attroff(A_REVERSE);
        }
        refresh();

        ch = getch();

        switch (ch) {
        case KEY_UP: {
            mode_opt_ = (mode_opt_ + 3 - 1) % 3;
            break;
        }
        case KEY_DOWN: {
            mode_opt_ = (mode_opt_ + 1) % 3;
            break;
        }
        case 10: {
            if (mode_opt_ == 2) {
                game_over_ = true;
            }
            return;
        }
        }
    } while (ch != 10);
}
void Game::render_style_opt(void) {
    if (mode_opt_ != 2) {
        start_color();
        int ch = ' ';
        do {
            clear();
            mvprintw(0, 0, "Please choose 1P's style:");
            if (mode_opt_ == 1)
                mvprintw(1, 0, "please choose 2P's style:");

            for (int i = 0; i < 4; i++) {
                if (i == style_opt[0]) {
                    attron(A_REVERSE);
                }
                if (mode_opt_ == 1)
                    if (i == style_opt[1]) {
                        attron(COLOR_PAIR(8));
                    }

                mvprintw(i + 2, 0, "%s", style_choice[i]);

                if (i == style_opt[0]) {
                    attroff(A_REVERSE);
                }
                if (mode_opt_ == 1)
                    if (i == style_opt[1]) {
                        attroff(COLOR_PAIR(8));
                    }
            }
            refresh();
            ch = getch();

            switch (ch) {
            case KEY_UP: {
                style_opt[0] = (style_opt[0] + 4 - 1) % 4;
                break;
            }
            case KEY_DOWN: {
                style_opt[0] = (style_opt[0] + 1) % 4;
                break;
            }
            case 'w': {
                if (mode_opt_ == 1)
                    style_opt[1] = (style_opt[1] + 4 - 1) % 4;
                break;
            }
            case 's': {
                if (mode_opt_ == 1)
                    style_opt[1] = (style_opt[1] + 1) % 4;
                break;
            }
            case 10: {
                // return;
                break;
            }
            }

        } while (ch != 10);
    }
}

void Game::start() {
    if (!snakes_.empty())
        snakes_.clear();
    game_over_ = false;

    if (mode_opt_ == 2) {
        return;
    } else if (mode_opt_ == 0) {

        snakes_.emplace_back(
            std::vector<Snake::Position>{{5, 5}, {6, 5}, {7, 5}});
        style_opt.push_back(0);
    } else if (mode_opt_ == 1) {

        snakes_.emplace_back(
            std::vector<Snake::Position>{{5, 7}, {6, 7}, {7, 7}});
        snakes_.emplace_back(
            std::vector<Snake::Position>{{5, 5}, {6, 5}, {7, 5}});

        style_opt.push_back(0);
        style_opt.push_back(1);
    }

    generate_food();

    collision_point_.clear();
}
// void Game::get_input() { input = getch(); }

// void Game::mytimer() {
//     while (keep_running_) {
//         get_input();
//         std::this_thread::sleep_for(std::chrono::milliseconds(interval_));
//     }
// }
