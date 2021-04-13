//
// Created by Tuuby on 14.04.2021.
//

#include "ImageResource.h"

ImageResource::ImageResource(std::filesystem::path *file, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->file = *file;
    this->texture = nullptr;
}

ImageResource::~ImageResource() {
    free(texture);
}

SDL_Texture *ImageResource::getTexture() {
    if (!std::filesystem::exists(file)) {
        logSDLError(std::cout, "ImageResource getTexture");
        return nullptr;
    }

    if (texture == nullptr) {
        texture = IMG_LoadTexture(renderer, file.string().c_str());
    }

    return texture;
}

ImageResource::ImageResource() {
    this->renderer = nullptr;
    this->file = "";
    this->texture = nullptr;
}


