//
// Created by Tuuby on 13.04.2021.
//

#ifndef GAMEENGINE_ANIMATION_H
#define GAMEENGINE_ANIMATION_H

#include <chrono>
#include <SDL.h>
#include "../resources/ImageResource.h"

using gameClock = std::chrono::high_resolution_clock;
using timePoint = std::chrono::time_point<std::chrono::steady_clock>;

class Animation {
private:
    int currentFrame;
    timePoint lastFrameTime;
    int frameCount;
public:
    ImageResource *frames;
    bool loop = true;
    int fps;

    Animation(int frameCount, int fps);
    ~Animation();
    void play();
    ImageResource* getImage() const;
};


#endif //GAMEENGINE_ANIMATION_H
