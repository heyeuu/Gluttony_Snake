#include <chrono>
#include <cstdio>
#include <ctime>

#include <ncurses.h>
#include <thread>

#include "game.hpp"

#include <cstdio>
#include <ctime>

#include <ncurses.h>

#include "game.hpp"

int main(void) {

    Game game;
    while (game.mode_opt_ != 2) {

        game.render_menu();
        game.render_style_opt();

        if (game.mode_opt_ == 2) {
            break;
        }
        game.start();
        game.run();
    }
    endwin();
}
