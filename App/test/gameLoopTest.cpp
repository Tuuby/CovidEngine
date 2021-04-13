//
// Created by Tuuby on 12.04.2021.
//

#define SDL_MAIN_HANDLED

#include <chrono>
#include "../../Engine/engine/GameLoop.h"

int main() {
    GameLoop gameLoop;

    std::chrono::high_resolution_clock::time_point t0;
    std::chrono::high_resolution_clock::time_point t1;

    std::chrono::seconds seconds;

    t0 = std::chrono::high_resolution_clock::now();
    do {
        t1 = std::chrono::high_resolution_clock::now();
        seconds = std::chrono::duration_cast<std::chrono::seconds>(t1 - t0);
    } while (seconds.count() <= 5);

    gameLoop.quit();

    return 0;
}