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

SDL_Texture* Graphics::loadTexture(const std::filesystem::path &file, SDL_Renderer *renderer) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.string().c_str());
    if (texture == nullptr) {
        logSDLError(std::cerr, "LoadTexture");
    }
    return texture;
}

SDL_Texture* Graphics::textToTexture(const std::string &message, const std::filesystem::path &fontFile, SDL_Color, int fontSize, SDL_Renderer *renderer) {
    auto font = std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)>(TTF_OpenFont(fontFile.string().c_str(), fontSize), TTF_CloseFont);
    if (font == nullptr) {
        logSDLError(std::cerr, "TTF_OpenFont");
        return nullptr;
    }
}
