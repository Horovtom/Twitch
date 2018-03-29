//
// Created by lactosis on 29.3.18.
//

#include "Texture.h"

int Texture::getId() const {
    return id;
}

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}

Texture::Texture() {
    id = -1;
}

Texture::Texture(int id) {
    this->id= id;
    if (!getTextureParams()) {
        cerr << "Failed to load texture with id: " << id << endl;
    }
}

Texture::Texture(string path) {
    id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);

    if (!getTextureParams()) {
        cerr << "Failed to load texture " << path << endl;
    }
}

bool Texture::getTextureParams() {
    if (id > 0) {
        int miplevel = 0;
        //Bind ID in gl
        glBindTexture(GL_TEXTURE_2D, id);
        //Get width and height of the texture
        glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &height);
        return true;
    } else {
        cerr << "Failed to register ID: " << id << endl;
        return false;
    }
}
