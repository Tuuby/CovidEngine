//
// Created by Tuuby on 12.04.2021.
//

#include "GameLoop.h"

GameLoop::GameLoop() :
    running(true), updateThread(&GameLoop::update, this), renderThread(&GameLoop::render, this) {
    std::cout << "GameLoop created" << std::endl;
}

GameLoop::~GameLoop() {
    updateThread.join();
    renderThread.join();
    std::cout << "GameLoop destroyed" << std::endl;
}

void GameLoop::update() {
    while (running) {
        std::lock_guard<std::mutex> locker(mutex);
        //std::cout << "Gameloop updated!" << std::endl;
    }
}

void GameLoop::render() {
    int fps = 0;
    auto lastFpsTime = gameClock::now();

    while (running) {
        auto const frameStartTime = gameClock::now();

        mutex.lock();
        //std::cout << "Gameloop rendered!" << std::endl;
        mutex.unlock();

        fps++;
        if (gameClock::now() >= lastFpsTime + seconds(1)) {
            std::cout << fps << "fps" << std::endl;
            fps = 0;
            lastFpsTime = gameClock::now();
        }

        auto frameDuration = gameClock::now() - frameStartTime;

        while (targetTime > frameDuration) {
            // Do fuck all
            frameDuration = gameClock::now() - frameStartTime;
        }
    }
}

long long GameLoop::currentMicroTime() {
    auto nano_since_epoch = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    return nano_since_epoch;
}
