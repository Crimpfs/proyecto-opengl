cmake_minimum_required(VERSION 3.10)
project(ProyectoOpenGL)

set(CMAKE_CXX_STANDARD 11)

# Agregar la carpeta include
include_directories(include)
include_directories(include/GL)
link_directories(lib)

# Agregar los archivos fuente
set(SOURCES
    src/main.cpp
    src/escena.cpp
    src/platillo.cpp
    src/input.cpp
    src/camara.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Vincular OpenGL y FreeGLUT
if(WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32 glu32 freeglut)
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} GL glut)
endif()
