#include <input.h>
#include <game.h>

InputScheme::InputScheme() {

}

InputScheme::InputScheme(std::vector<InputAction> &Actions) {
    actions = Actions;
}

void Input::Handle(SDL_Scancode key) {
    for (auto i : InputScheme::Current.actions) {
        i.
    }
}