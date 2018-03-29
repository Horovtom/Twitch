//
// Created by lactosis on 29.3.18.
//

#ifndef TWITCH_ENGINE_H
#define TWITCH_ENGINE_H

#include <iostream>
#include "GLFW/glfw3.h"
#include "GL/gl.h"

using namespace std;

class Engine {
public:
    static int SCREEN_WIDTH, SCREEN_HEIGHT;

    Engine();
    ~Engine();

    bool initialize(char * windowTitle);

    void update();

    void beginRender();

    void endRender();

private:
    static GLFWwindow * window;
};



#endif //TWITCH_ENGINE_H
