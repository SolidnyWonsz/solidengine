#pragma once

#include <vector>
#include <string>
#include <renderer/mesh.h>

class Scene {
    public:
        Scene(const std::string name);

        const std::string Name;
        std::vector<Mesh> meshes;

        void Draw();
        void SpawnMesh(const char *path);

    public:
        static void Initialize();
        static Scene *GetScene();
        static void ChangeScene(const Scene &scene);
        static void ChangeScene(const std::string &name);
};