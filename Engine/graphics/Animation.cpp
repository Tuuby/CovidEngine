//
// Created by Tuuby on 13.04.2021.
//

#include "Animation.h"

Animation::Animation(int frameCount, int fps) {
    currentFrame = 0;
    this->frameCount = frameCount;
    lastFrameTime = gameClock::now();
    frames = new ImageResource[frameCount];
    this->fps = fps;
}

Animation::~Animation() {
    delete[] frames;
}

void Animation::play() {
    timePoint currentTime = gameClock::now();

    if (currentTime > lastFrameTime + std::chrono::nanoseconds(std::chrono::seconds(1) / fps)) {
        currentFrame++;

        if (currentFrame >= frameCount) {
            if (loop) {
                currentFrame = 0;
            } else {
                currentFrame--;
            }
        }

        lastFrameTime = currentTime;
    }
}

ImageResource *Animation::getImage() const {
    return &frames[currentFrame];
}
