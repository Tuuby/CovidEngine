//
// Created by Tuuby on 26.04.2021.
//

#ifndef GAMEENGINE_PARTICLE_H
#define GAMEENGINE_PARTICLE_H

class Particle {
private:
    int posX;
    int posY;
    int width;
    int height;
    double opacity;
public:
    Particle(int posX, int posY, int width, int height, double opacity, void (*update)(int, int, Particle));
    Particle();

    void setWidth(int width);
    void setHeight(int height);
    void setOpacity(double opacity);
    void setPosX(int x);
    void setPosY(int y);

    void (*update)(int, int, Particle);
};

#endif //GAMEENGINE_PARTICLE_H