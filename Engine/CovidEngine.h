//
// Created by Tuuby on 10.04.2021.
//

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

void logSDLError(std::ostream &ostream, const std::string &msg) {
    ostream << msg << " error: " << SDL_GetError() << std::endl;
}

void init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        logSDLError(std::cerr, "SDL_Init");
        return;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        logSDLError(std::cerr, "IMG_Init");
        SDL_Quit();
        return;
    }

    if (TTF_Init() != 0) {
        logSDLError(std::cerr, "TTF_Init");
        SDL_Quit();
        return;
    }
}

void quit() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}