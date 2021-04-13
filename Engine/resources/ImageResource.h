//
// Created by Tuuby on 14.04.2021.
//

#ifndef GAMEENGINE_IMAGERESOURCE_H
#define GAMEENGINE_IMAGERESOURCE_H

#include <SDL.h>
#include <SDL_image.h>
#include <filesystem>
#include "../CovidEngine.h"

class ImageResource {
private:
    SDL_Texture *texture;
    std::filesystem::path file;
    SDL_Renderer *renderer;
public:
    ImageResource(std::filesystem::path *file, SDL_Renderer *renderer);
    ~ImageResource();
    SDL_Texture* getTexture();
};


#endif //GAMEENGINE_IMAGERESOURCE_H
