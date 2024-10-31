#pragma once
#include <atomic>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

#include "snake.hpp"

class Game {
public:
    Game();

    void run();
    void render_menu();
    void render_style_opt();
    void start();
    const char *menu_choice[3] = {"Single_Player", "Double_Player", "Exit"};
    const char *style_choice[4] = {"Yellow", "Blue", "Cyan", "Green"};

    // struct Style_choice {
    std::vector<int> style_opt{0};
    // };
    // int style_opt_{0};
    // int style_opt_2{1};
    int mode_opt_{0};
    bool game_over_;
    // Style_choice style_opts_;

private:
    void generate_food();

    void parse_input();
    void get_input();
    void step();

    void render();

    void mytimer();
    static constexpr int width = 20;
    static constexpr int height = 20;

    int interval_{500};
    // int input;
    std::atomic<bool> keep_running_{true};

    Snake::Position food_;

    std::vector<Snake::Position> collision_point_;
    std::vector<Snake> snakes_;
};