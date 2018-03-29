#include "engine/Engine.h"
#include "engine/graphics/Sprite.h"
#include <iostream>

int main() {
    cout << "Hello twitch" << endl;

    Engine engine;
    if (!engine.initialize(const_cast<char *>("Twitch"))) {
        cerr << "Failed to initialize engine!" << endl;
        return -1;
    }

    Sprite testSprite = Sprite("assets/art/Biplane.png", -100,-100);

    while(true) {
        engine.update();
        testSprite.update();

        engine.beginRender();

        testSprite.render();

        engine.endRender();
    }

    return 0;
}
