#include <renderer/shader.h>
#include <SDL2/SDL.h>
#include <gl/glew.h>

Shader::Shader(const char *vertexShaderCode, const char *fragmentShaderCode) {
    Create(vertexShaderCode, fragmentShaderCode);
    glUseProgram(Program);
}

Shader::~Shader() {
    if (Program != 0) {
        glDeleteProgram(Program);
    }
}

void Shader::Create(const char *vertexSource, const char *fragmentSource) {
    uint32_t vertexShader = Compile(vertexSource, GL_VERTEX_SHADER);
    uint32_t fragmentShader = Compile(fragmentSource, GL_FRAGMENT_SHADER);

    Program = glCreateProgram();
    
    glAttachShader(Program, vertexShader);
    glAttachShader(Program, fragmentShader);

    glLinkProgram(Program);

    int result;
    char errorStr[512];
    glGetShaderiv(Program, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        glGetShaderInfoLog(Program, 512, NULL, errorStr);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer - OpenGL", errorStr, NULL);
        exit(EXIT_FAILURE);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

uint32_t Shader::Compile(const char *source, uint32_t type) {
    uint32_t handle = glCreateShader(type);
    glShaderSource(handle, 1, &source, nullptr);
    glCompileShader(handle);

    int result;
    char errorStr[512];
    glGetShaderiv(handle, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        glGetShaderInfoLog(handle, 512, NULL, errorStr);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer - OpenGL", errorStr, NULL);
        exit(EXIT_FAILURE);
    }

    return handle;
}

void Shader::Run() {
    glUseProgram(Program);
}