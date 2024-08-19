#pragma once

#include <SDL2/SDL_keycode.h>
#include <vector>

class InputScheme;

namespace Input {
    void Handle(SDL_Scancode Key);
    void ChangeScheme(InputScheme &NewScheme);
}

struct Key {
    SDL_Scancode SDLKey;
    bool Pressed;
};

struct InputAction {
    const char *Action;
    Key Key;
};

class InputScheme {
    public:
        InputScheme();
        InputScheme(std::vector<InputAction> &Actions);
        ~InputScheme();

        std::vector<InputAction> actions;

        static InputScheme &Current;
        static InputScheme Paused;
        static InputScheme Game;
        static InputScheme GUI;
};