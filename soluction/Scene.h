#pragma once
#include <GL/glew.h>

class Scene {
    public:
        ~Scene() { }
        virtual void update() = 0;
};
