//
// Created by lactosis on 29.3.18.
//

#ifndef TWITCH_SPRITE_H
#define TWITCH_SPRITE_H

#include "Texture.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>

using namespace std;

class Sprite {
public:
    Sprite();
    explicit Sprite(string imagePath);
    Sprite(string imagePath, float xPos, float yPos);
    void update();
    void render();

private:
    Texture texture;
    float xPos, yPos;
};


#endif //TWITCH_SPRITE_H
