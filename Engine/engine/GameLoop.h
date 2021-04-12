//
// Created by Tuuby on 12.04.2021.
//

#ifndef GAMEENGINE_GAMELOOP_H
#define GAMEENGINE_GAMELOOP_H

#include <mutex>
#include <thread>
#include <iostream>

class GameLoop {
private:
    volatile bool running;
    std::mutex mutex;
    std::thread renderThread;
    std::thread updateThread;

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
