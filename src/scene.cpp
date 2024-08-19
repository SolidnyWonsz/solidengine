#include <scene.h>

static Scene *curr;

Scene::Scene(const std::string name) : Name(name) {

}

void Scene::Draw() {
    
}

void Scene::Initialize() {
    static Scene basicScene = Scene("basicScene");
    curr = &basicScene;
}

Scene *Scene::GetScene() {
    return curr;
}