#include <windows.h>
#include <game.h>

int main(int, char**) {
    Game &game = Game::GetInstance();
    game.Start("SolidEngine", 640, 480);
    game.Run();

    return 0;
}