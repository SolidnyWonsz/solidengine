#include <loaders/obj.h>
#include <fstream>
#include <sstream>
#include <string>
#include <SDL2/SDL.h>
#include <common/tokenizer.h>

using namespace Loader;

#define Comment "#"
#define Vertex "v"
#define Indices "f"

OBJ::OBJ(const char *path) {
    if (!path) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "SolidEngine", "Invalid path", NULL);
        throw std::runtime_error("Invalid path");
    }
    std::ifstream file(path);

    if (!file) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "SolidEngine", "Failed to open OBJ", NULL);
        throw std::runtime_error("Failed to open OBJ");
    }

    for (std::string line; getline(file, line);) {
        Common::Tokenizer token(line, ' ');

        // I really had no idea how to name this variable, sowwy.
        // It defines what type of stuff the line defines, whether it's
        // vertex, normal, comment, whatever.
        std::string lineType = token.next();

        // Shit's gonna look ugly asf unfortunately
        if (lineType == Comment) {
            continue;
        } else 
        if (lineType == Vertex) {
            // There should be just three floats, right?? RIGHT??
            for (int i = 0; i < 3; i++) {
                std::string vertexPoint = token.next();

                // TODO:
                // Check whether the OBJ is fucked so the engine
                // won't load the model if there's less than 3 vertices
                // in the line.
                if (!vertexPoint.empty()) {
                    vertices.push_back(std::stof(vertexPoint));
                }
            }
        } else
        if (lineType == Indices) {
            for (int i = 0; i < 3; i++) {
                std::string index = token.next();
                // A little hack to only get the vertex index
                unsigned int vindex = index[0] - 48;
                if (!index.empty()) {
                    indices.push_back(vindex);
                }
            }
        }
    }
}

std::vector<float> &OBJ::GetVertices() {
    return vertices;
}

std::vector<unsigned int> &OBJ::GetIndices() {
    return indices;
}