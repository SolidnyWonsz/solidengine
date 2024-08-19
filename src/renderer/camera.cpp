#include <renderer/camera.h>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position) {
    Position = position;
    Target = position + glm::vec3(0,0,3);
    Direction = glm::normalize(Position - Target);
    Right = glm::normalize(glm::cross(glm::vec3(0, 1, 0), Target));
    Up = glm::cross(Direction, Right);
    ViewMatrix = glm::lookAt(Position, Target, Up);
}