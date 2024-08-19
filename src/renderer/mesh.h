#pragma once

#include <vector>
#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 Position, Normal, TexCoords;
};

class Mesh {
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        void Draw();

    private:
        unsigned int VBO, VAO, EBO;
        std::vector<Vertex> Vertices;
        std::vector<unsigned int> Indices;
        void Setup();
};