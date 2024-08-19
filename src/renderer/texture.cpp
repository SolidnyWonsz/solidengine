#include <renderer/texture.h>

#include <GL/glew.h>

Texture::Texture(const char *path) {
    glBindTexture(1, ID);
}