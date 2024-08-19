#pragma once

#include <glm/glm.hpp>

class Camera {
    public:
        Camera(glm::vec3 position);
        ~Camera();

        glm::vec3 Position;
        glm::vec3 Target;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 Direction;

        float FoV;

    private:
        glm::mat4 ViewMatrix;
};