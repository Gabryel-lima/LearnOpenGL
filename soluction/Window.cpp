#include "Window.h"
#include "Scene.h"

#include <iostream>

Window::Window(int width, int heigth, const char* title) {

    // Inicializando o objeto de constução da janela.
    if (!glfwInit()) {
        std::cerr << "Erro de inicialização da janela." << std::endl;
        return;
    }
    
    // Definição dos atributos de contexto OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwSetErrorCallback(Window::errorCalback);

    // Criar a janela
    m_Window = glfwCreateWindow(width, heigth, title, NULL, NULL);

    if (!m_Window) {
        std::cerr << "Erro em criar a janela" << std::endl;
        glfwTerminate();
        return;
    }

    // Torna o contexto atual
    glfwMakeContextCurrent(m_Window);

    glewExperimental = GL_TRUE;
    
    GLenum glewInitErr = glewInit();

    if (glewInitErr != GLEW_OK) {
        std::cerr << "Erro ao inicializar GLEW: " << glewGetErrorString(glewInitErr) << std::endl;
        return;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Define o fundo como preto
    m_ShouldClose = false;

}

void Window::update() {
    if (glfwWindowShouldClose(m_Window)) {
        m_ShouldClose = true;
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (m_Scene) {
        m_Scene -> update();
    }

    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

Window::~Window() {
    if (m_Window) {
        glfwDestroyWindow(m_Window);
    }
    glfwTerminate();
}

void Window::errorCalback(int error, const char* description) {
    std::cerr << "Erro " << error << ": " << description << std::endl;
}
