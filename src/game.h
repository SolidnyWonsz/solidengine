#pragma once

#include <renderer/renderer.h>

class Game {
    public:
        void Start(const char *title, int width, int height);
        void Run();
        void Pause(bool pause);
        bool IsPaused();
        double GetDeltaTime();

        enum class State {
            Uninitialized,
            Running,
            Paused
        } State;

        CRenderer *Renderer;

        static Game &GetInstance() {
            static Game instance;
            return instance;
        }

        bool Running;

        Game(const Game&) = delete;
        void operator=(const Game&) = delete;

    private:
        Game() {}
        
        double fDeltaTime;
        bool bIsPaused;
};