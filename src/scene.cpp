#include <scene.h>
#include <SDL2/SDL.h>
#include <iostream>

static Scene *curr;

Scene::Scene(const std::string name) : Name(name) {
    
}

void Scene::Draw() {
    std::cout << meshes.size() << std::endl;
}

void Scene::Initialize() {
    static Scene basicScene = Scene("basicScene");
    curr = &basicScene;
}

Scene *Scene::GetScene() {
    if (curr == nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SolidEngine", "Scene doesn't exist! GET OUT, QUICK!", NULL);
        exit(1);
    }
    return curr;
}