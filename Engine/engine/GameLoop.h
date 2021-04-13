//
// Created by Tuuby on 12.04.2021.
//

#ifndef GAMEENGINE_GAMELOOP_H
#define GAMEENGINE_GAMELOOP_H

#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

using gameClock = std::chrono::high_resolution_clock;
using nanos = std::chrono::nanoseconds;
using seconds = std::chrono::seconds;

class GameLoop {
private:
    const int targetFPS = 144;
    const nanos targetTime = nanos(seconds(1)) / targetFPS;

    volatile bool running;
    std::mutex mutex;
    std::thread renderThread;
    std::thread updateThread;

    static long long currentMicroTime();
    void update();
    void render();
public:
    GameLoop();
    ~GameLoop();
    inline void quit() {
        running = false;
    }
};


#endif //GAMEENGINE_GAMELOOP_H
