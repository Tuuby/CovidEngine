//
// Created by Tuuby on 10.04.2021.
//

#ifndef GAMEENGINE_GRAPHICS_H
#define GAMEENGINE_GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <filesystem>
#include "../CovidEngine.h"

class Graphics {
public:
    // This method converts an imagefile to an internal SDL_Texture
    static SDL_Texture* loadTexture(const std::filesystem::path &file, SDL_Renderer *renderer);

    static std::shared_ptr<SDL_Texture> textToTexture(const std::string &message, const std::filesystem::path &fontFile, SDL_Color, int fontSize, SDL_Renderer *renderer);
    // This method draws the given texture into the specified targetArea and scales it accordingly
    static void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect targetArea, SDL_Rect *sourceSection = nullptr);
    // This method draws the given texture at the specified position and keeps the original size
    static void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceSection = nullptr);
};


#endif //GAMEENGINE_GRAPHICS_H
