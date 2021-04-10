//
// Created by Tuuby on 10.04.2021.
//

#ifndef GAMEENGINE_WINDOWMANAGER_H
#define GAMEENGINE_WINDOWMANAGER_H

#include <memory>
#include <SDL.h>
#include <string>

class WindowManager {
private:
    std::string title;
    int xPosition;
    int yPosition;
    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
public:
    WindowManager();
    WindowManager(const std::string *title, int xPosition, int yPosition, int screenWidth, int screenHeight, Uint32 flags);
    virtual ~WindowManager();

    // Returns a primitive pointer to the window
    const SDL_Window* getWindow();

    // Call this when an SDL_WindowEvent is registered that changed the window size
    void reshape();
};


#endif //GAMEENGINE_WINDOWMANAGER_H
