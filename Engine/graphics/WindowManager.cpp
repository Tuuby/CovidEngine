//
// Created by Tuuby on 10.04.2021.
//

#include "WindowManager.h"

WindowManager::WindowManager()
    : title("Default"), xPosition(100), yPosition(100), SCREEN_WIDTH(1280), SCREEN_HEIGHT(720),
    window(SDL_CreateWindow("Default", 100, 100, 1280, 720, SDL_WINDOW_SHOWN), SDL_DestroyWindow) {
}

WindowManager::WindowManager(const std::string *title, int xPosition, int yPosition, int screenWidth, int screenHeight, Uint32 flags)
        : title(*title), xPosition(xPosition), yPosition(yPosition), SCREEN_WIDTH(screenWidth),
          SCREEN_HEIGHT(screenHeight), window(SDL_CreateWindow(title->c_str(), xPosition, yPosition, screenWidth, screenHeight, flags), SDL_DestroyWindow) {
}

WindowManager::~WindowManager() {

}

const SDL_Window* WindowManager::getWindow() {
    return window.get();
}

void WindowManager::reshape() {
    SDL_GetWindowSize(window.get(), &SCREEN_WIDTH, &SCREEN_HEIGHT);
}
