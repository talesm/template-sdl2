#include <iostream>
#include <SDL2pp/SDL2pp.hh>

int
main(int argc, char** argv)
{
  using namespace SDL2pp;
  SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
  SDL library{SDL_INIT_EVERYTHING};

  Point  windowSz{1024, 768};
  Window window{"Hello world",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                windowSz.x,
                windowSz.y,
                SDL_WINDOW_RESIZABLE};

  Renderer renderer{window, -1, SDL_RENDERER_ACCELERATED};
  bool     done = false;
  while (!done) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      switch (ev.type) {
        case SDL_QUIT:
          done = true;
          break;
        case SDL_WINDOWEVENT:
          switch (ev.window.event) {
            case SDL_WINDOWEVENT_SIZE_CHANGED:
              windowSz.x = ev.window.data1;
              windowSz.y = ev.window.data2;
              break;

            default:
              break;
          }
        default:
          break;
      }
    }

    renderer.SetDrawColor(127, 127, 224, 255);
    renderer.FillRect(Point{0, 0}, windowSz);
    renderer.Present();

    SDL_Delay(1);
  }

  return 0;
}
