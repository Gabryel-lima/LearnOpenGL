#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "Scene.h"

class Scene;

class Window {
    public:
        Window(int width = 800, int height = 600, const char* title = "");
        void update();
        ~Window();

    inline bool shouldClose() const { return m_ShouldClose; }
    inline void setScene(std::unique_ptr<Scene> scene) { m_Scene = std::move(scene); }

private:
    GLFWwindow* m_Window;
    bool m_ShouldClose;
    std::unique_ptr<Scene> m_Scene = nullptr;
    static void errorCalback(int error, const char* description);
};
