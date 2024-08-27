#pragma once

#include <common/defines.h>
#include <vector>
#include <glm/glm.hpp>

class Mesh {
    public:
        Mesh(const char *path);
        void Draw();

    private:
        unsigned int VBO, VAO, EBO;
        std::vector<float> Vertices;
        std::vector<unsigned int> Indices;
        void Setup();
};