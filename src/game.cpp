#include <game.h>
#include <SDL2/SDL.h>
#include <scene.h>

void Game::Start(const char *title, int width, int height) {
    State = State::Uninitialized;
    Renderer = new CRenderer(title, width, height);
    Running = true;
    State = State::Running;
    Scene::Initialize();
}

bool Game::IsPaused() { return bIsPaused; }
double Game::GetDeltaTime() { return fDeltaTime; }

void Game::Run() {
    if (State == State::Uninitialized) {
        return;
    }
    
    uint64_t currTime = SDL_GetPerformanceCounter();
    uint64_t lastTime = 0;
    while (Running) {
        lastTime = currTime;
        currTime = SDL_GetPerformanceCounter();
        fDeltaTime = (double)((lastTime - currTime)*1000 / (double)SDL_GetPerformanceCounter());

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    Running = false;
                    break;
                case SDL_KEYDOWN:
                    if (e.key.keysym.sym == SDLK_f) {
                        Renderer->setWireframe(!Renderer->getWireframe());
                    }
            }
        }

        Renderer->Draw();
    }
}