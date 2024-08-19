#include <game.h>

#ifdef WIN32
#include <windows.h>
#endif

int main(int, char**) {
    #ifdef WIN32
    //FreeConsole();
    #endif
    Game &game = Game::GetInstance();
    game.Start("SolidEngine", 640, 480);
    game.Run();

    return 0;
}