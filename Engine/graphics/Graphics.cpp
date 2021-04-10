//
// Created by Tuuby on 10.04.2021.
//

#include "Graphics.h"

void Graphics::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect targetArea, SDL_Rect *sourceSection) {
    SDL_RenderCopy(renderer, texture, sourceSection, &targetArea);
}

void Graphics::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceSection) {
    SDL_Rect targetArea;
    targetArea.x = x;
    targetArea.y = y;

    if (sourceSection != nullptr) {
        targetArea.w = sourceSection->w;
        targetArea.h = sourceSection->h;
    } else {
        SDL_QueryTexture(texture, NULL, NULL, &targetArea.w, &targetArea.h);
    }
    renderTexture(texture, renderer, targetArea, sourceSection);
}
