#include <scene.h>
#include <SDL2/SDL.h>
#include <iostream>

static Scene *curr;
std::vector<Scene> scenes;

Scene::Scene(const std::string name) : Name(name) {
    scenes.push_back(*this);
}

void Scene::Draw() {
    for (Mesh mesh : meshes) {
        //printf("Drawing mesh\n");
        mesh.Draw();
    }
    //printf("Finishing drawing mesh\n");
}

void Scene::SpawnMesh(const char *path) {
    if (curr == nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "SolidEngine", "Couldn't spawn mesh - no scene loaded", NULL);
        return;
    }

    Mesh *mesh = new Mesh(path);
    meshes.push_back(*mesh);

    printf("Mesh spawned\n");
}

void Scene::Initialize() {
    static Scene basicScene = Scene("basicScene");
    curr = &basicScene;
    basicScene.SpawnMesh("assets/untitled.obj");
}

Scene *Scene::GetScene() {
    if (curr == nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SolidEngine", "Scene doesn't exist! GET OUT, QUICK!", NULL);
        exit(1);
    }
    return curr;
}

void Scene::ChangeScene(const Scene &scene) {

}

void Scene::ChangeScene(const std::string &name) {

}