#pragma once

class Shader {
    public:
        Shader(const char *vertexShaderCode, const char *fragmentShaderCode);
        ~Shader();

        unsigned int GetProgram() { return Program; }

        //Use Run() to switch shaders!
        void Run();

    private:
        unsigned int Program;

        void Create(const char *vertexSource, const char *fragmentSource);
        unsigned int Compile(const char *source, unsigned int type);
};