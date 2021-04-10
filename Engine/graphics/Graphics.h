//
// Created by Tuuby on 10.04.2021.
//

#ifndef GAMEENGINE_GRAPHICS_H
#define GAMEENGINE_GRAPHICS_H

#include <SDL.h>

class Graphics {
public:
    // This method draws the given texture into the specified targetArea and scales it accordingly
    static void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect targetArea, SDL_Rect *sourceSection = nullptr);
    // This method draws the given texture at the specified position and keeps the original size
    static void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceSection = nullptr);
};


#endif //GAMEENGINE_GRAPHICS_H
