cmake_minimum_required(VERSION 3.10)
project(OpenGLTutorial)

# Define o padrão de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

include_directories(
    glad/include
)

add_executable(cosm main.cpp)

target_link_libraries(cosm
    glad
    glfw
    GL
    m
)


# # Diretório de dependências
# set(DEP_DIR "${CMAKE_SOURCE_DIR}/dep")

# # Configura o GLEW no Windows
# set(GLEW_INCLUDE_DIR "${DEP_DIR}/glew-2.1.0/include")
# set(GLEW_LIBRARY "${DEP_DIR}/glew-2.1.0/lib/Release/Win32/glew32.lib")
# set(GLEW_DLL "${DEP_DIR}/glew-2.1.0/bin/Release/Win32/glew32.dll")

# # Configura o GLFW
# set(GLFW_INCLUDE_DIR "${DEP_DIR}/glfw-3.4/include")
# set(GLFW_LIBRARY "${DEP_DIR}/glfw-3.4/lib-mingw-w64/libglfw3dll.a")
# set(GLFW_DLL "${DEP_DIR}/glfw-3.4/lib-mingw-w64/glfw3.dll")

# # Configura o GLM
# set(GLM_INCLUDE_DIR "${DEP_DIR}/glm")  # Adicionando o GLM

# # Adiciona os diretórios de include
# include_directories(${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

# # Adiciona o executável principal
# add_executable(soluction main.cpp Window.cpp MyScene.cpp)

# # Configura as bibliotecas de linkagem
# target_link_libraries(soluction ${GLEW_LIBRARY} ${GLFW_LIBRARY} opengl32)

# # Copia a DLL do GLEW para o diretório de build
# add_custom_command(TARGET soluction POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     "${GLEW_DLL}" $<TARGET_FILE_DIR:soluction>)

# # Copia a DLL do GLFW para o diretório de build
# add_custom_command(TARGET soluction POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     "${GLFW_DLL}" $<TARGET_FILE_DIR:soluction>)

# # Mensagens informativas
# message(STATUS "GLEW Include: ${GLEW_INCLUDE_DIR}")
# message(STATUS "GLFW Include: ${GLFW_INCLUDE_DIR}")
# message(STATUS "GLEW Library: ${GLEW_LIBRARY}")
# message(STATUS "GLFW Library: ${GLFW_LIBRARY}")
