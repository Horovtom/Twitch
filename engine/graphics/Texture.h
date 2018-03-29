//
// Created by lactosis on 29.3.18.
//

#ifndef TWITCH_TEXTURE_H
#define TWITCH_TEXTURE_H

#include "GLFW/glfw3.h"
#include "SOIL/SOIL.h"
#include <iostream>
#include <string>

using namespace std;
class Texture {
public:
    Texture();

    explicit Texture(int id);

    explicit Texture(string path);

    int getId() const;

    int getWidth() const;

    int getHeight() const;

private:
    int id, width, height;
    bool getTextureParams();
};


#endif //TWITCH_TEXTURE_H
