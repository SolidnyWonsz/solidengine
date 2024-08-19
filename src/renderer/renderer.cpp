#include <renderer/renderer.h>
#include <renderer/shader.h>
#include <gl/glew.h>
#include <SDL2/SDL_opengl.h>
#include <gl/glu.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <scene.h>

static SDL_Window *window;

const char *vertexShaderData =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main() {\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderData =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";


CRenderer::CRenderer(const char *title, int width, int height) {
    const char *description;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer", "Failed to init SDL", NULL);
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED);
    if (!window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer", "Failed to create window", NULL);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GLContext gContext = SDL_GL_CreateContext(window);
    if (gContext == NULL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer - OpenGL", SDL_GetError(), window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    glewInit();

    Shader *shader = new Shader(vertexShaderData, fragmentShaderData);
}

CRenderer::~CRenderer() {

}

void CRenderer::Draw() {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Scene::GetScene()->Draw();

    SDL_GL_SwapWindow(window);
}

void CRenderer::setFullscreen(bool fullscreen) {
    SDL_SetWindowFullscreen(window, !fullscreen);
}

bool CRenderer::isFullscreen() {
    return SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;
}

Resolution CRenderer::getResolution() {
    Resolution res;
    SDL_GetWindowSize(window, &res.Width, &res.Height);
    return res;
}

SDL_Window *CRenderer::GetWindowHandle() {
    return window;
}