cmake_minimum_required(VERSION 3.10)
project(ProyectoOpenGL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 0)

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

# Copiar la DLL al directorio de compilación para que el programa pueda ejecutarse
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/lib/libfreeglut.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# Vincular OpenGL y FreeGLUT
if(WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32 glu32 freeglut)
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} GL glut)
endif()
