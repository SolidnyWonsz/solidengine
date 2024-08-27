#pragma once

#include <SDL2/SDL.h>

struct Resolution {
    int Width, Height;
};

class CRenderer {
    public:
        CRenderer(const char *title, int width, int height);
        ~CRenderer();

        void Draw();
        void HandleEvents();

        SDL_Window *GetWindowHandle();

        //Window related
        void setFullscreen(bool fullscreen);
        bool isFullscreen();

        Resolution getResolution();

        void setWireframe(bool wireframe);
        bool getWireframe();

    private:
        bool wireframe;
};