//
// Created by lactosis on 29.3.18.
//

#include "Sprite.h"

Sprite::Sprite() {
    xPos = yPos = 0;
    texture= Texture();
}

Sprite::Sprite(string imagePath) {
    texture = Texture(imagePath);
    xPos= 0;
    yPos = 0;
}

Sprite::Sprite(string imagePath, float xPos, float yPos) {
    texture = Texture(imagePath);
    this->xPos= xPos;
    this->yPos = yPos;
}

void Sprite::update() {
    //TODO: IMPL
}

void Sprite::render() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>(texture.getId()));
    //Reset camera
    glLoadIdentity();

    //workflow:
    //translate -> rotate -> scale
    glTranslatef(xPos, yPos, 0);
    //glScalef()


    //Rendering
    glColor4f(1,1,1,1);
    //Begin drawing
    glBegin(GL_QUADS);

    //now we will go counter-clockwise and specify where vertices of the image will be
    //Because we are translated to xPos and yPos we don't need to specify xPos and yPos in coordinates

    //We want to put bottom left corner of the image
    glTexCoord2f(0,0);
    //to xPos and yPos
    glVertex2f(0, 0);

    //We want to put bottom right corner of the image
    glTexCoord2f(1, 0);
    //to xPos + width and yPos
    glVertex2f(0 + texture.getWidth(), 0);

    //We want to put top right corner of the image
    glTexCoord2f(1,1);
    //to xPos and yPos
    glVertex2f(0 + texture.getWidth(), 0 + texture.getHeight());

    //We want to put top left corner of the image
    glTexCoord2f(0,1);
    //to xPos and yPos
    glVertex2f(0, 0 + texture.getHeight());
    //End drawing
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
