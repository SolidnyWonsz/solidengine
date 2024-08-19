#pragma once

#include <renderer/mesh.h>
#include <string>

class Scene {
    public:
        Scene(const std::string name);

        const std::string Name;
        std::vector<Mesh> Meshes;

        void Draw();

    public:
        static void Initialize();
        static Scene *GetScene();
        static void ChangeScene(const Scene &scene);
};