//
// Created by lactosis on 29.3.18.
//

#include "Engine.h"

int Engine::SCREEN_WIDTH= 1024;
int Engine::SCREEN_HEIGHT = 1024;
GLFWwindow * Engine::window = NULL;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::initialize(char *windowTitle) {
    if (!glfwInit()) {
        cerr<< "Error initializing glfw!" << endl;
        return false;
    }

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

    if (window == NULL) {
        cerr << "Error creating window" << endl;
        return false;
    }

    // region GLFW setup
    glfwMakeContextCurrent(window);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    /*
     * We have two buffers in glfw,
     *  front buffer - what is currently on screen
     *  back buffer - what we are drawing into
     * Buffers swap on an interval and we set it now to every frame
     */
    glfwSwapInterval(1);

    //This gets current active monitor reference to use it's properties
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //Get the center points for our screen
    int xPos = (mode->width - SCREEN_WIDTH) / 2;
    int yPos = (mode->height - SCREEN_HEIGHT) / 2;

    glfwSetWindowPos(window, xPos, yPos);

    //endregion

    //region GL setup
    //Viewport
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //What dimensions we can use. The Z coordinates -10 and 10 are there for layering assets
    glOrtho(0 ,width, 0, height, -10 , 10);
    glDepthRange(-10, 10);

    glMatrixMode(GL_MODELVIEW);

    //We want to use alpha blending for .png with transparency
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //endregion

    return true;
}

void Engine::update() {
    glfwPollEvents();
}

void Engine::beginRender() {
    //Set up buffer switch

    //Clear buffer with a blue color
    glClearColor(0, 0, 1, 1);
    //Clear depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::endRender() {
    glfwSwapBuffers(window);
}
