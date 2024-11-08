#pragma once

#include "snake.hpp"
#include <atomic>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <queue>
#include <vector>
class Ai_snake;
class Game;
class Map {
public:
    bool obstacle_map[20][20];
    int snake_map[20][20];

    void init_wall_map(void);

    void init_snake_map(Game game);
    void set_snake_map();

private:
};

class Game {
public:
    Game();

    void run();
    void render_menu();
    void render_style_opt();
    void start();

    const char *menu_choice[3] = {
        "Single_Player Battle", "Double_Player_Battle", "Exit"};
    const char *style_choice[4] = {"Yellow", "Blue", "Cyan", "Green"};

    std::vector<int> style_opt{0};

    Snake::Position food_;
    int mode_opt_{0};
    bool game_over_;

    std::vector<Ai_snake> ai_snakes_;

protected:
private:
    void generate_food();

    void parse_input();
    void get_input();
    void step();

    void render();

    // void mytimer();
    static constexpr int width = 20;
    static constexpr int height = 20;

    std::vector<Snake::Position> collision_point_;
    std::vector<Snake> snakes_;
    Map map;
};
class Engine {
public:
private:
};