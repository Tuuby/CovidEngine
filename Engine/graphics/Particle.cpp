//
// Created by Tuuby on 26.04.2021.
//

#include "Particle.h"

void defaultBehaviour(int x, int y, Particle p) {
    y += 1;
    p.setPosX(x);
    p.setPosY(y);
}

void Particle::setPosX(int x) {
    Particle::posX = x;
}

void Particle::setPosY(int y) {
    Particle::posY = y;
}

Particle::Particle() {
    posX = 0;
    posY = 0;
    width = 10;
    height = 10;
    opacity = 1;
    update = defaultBehaviour;
}

Particle::Particle(int posX, int posY, int width, int height, double opacity, void (*update)(int, int, Particle))
        : posX(posX), posY(posY), width(width), height(height), opacity(opacity), update(update) {}

void Particle::setWidth(int width) {
    Particle::width = width;
}

void Particle::setHeight(int height) {
    Particle::height = height;
}

void Particle::setOpacity(double opacity) {
    Particle::opacity = opacity;
}

