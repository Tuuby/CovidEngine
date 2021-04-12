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
        std::cout << "Gameloop updated!" << std::endl;
    }
}

void GameLoop::render() {
    while (running) {
        std::lock_guard<std::mutex> locker(mutex);
        std::cout << "Gameloop rendered!" << std::endl;
    }
}
