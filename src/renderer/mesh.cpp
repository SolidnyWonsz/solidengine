#include <renderer/mesh.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <loaders/obj.h>
#include <common/logging.h>
#include <stdio.h>

Mesh::Mesh(const char *path) {
    Loader::OBJ obj(path);
    Vertices = obj.GetVertices();
    Indices = obj.GetIndices();
    DebugPrint();
    Setup();
}

void Mesh::Draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::DebugPrint() {
    Logging::Log(Logging::Information, "MESH INFORMATION\nMesh vertices: %d\nMesh indices: %d\nMesh vertex array: ", Vertices.size(), Indices.size());
    for (int i = 0; i < Vertices.size(); i++) {
        fprintf(stderr, "%f ", Vertices[i]);
    }

    fprintf(stderr, "\nMesh index array: ");
    for (int i = 0; i < Indices.size(); i++) {
        fprintf(stderr, "%d ", Indices[i]);
    }
    fprintf(stderr, "\n");
}

void Mesh::Setup() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(float), &Vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}