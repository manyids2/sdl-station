#include "Log.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_timer.h"
#include "Settings.h"
#include "renderers/Renderer.h"
#include <csignal>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

bool parseArgs(int argc, char *argv[]) {
  Settings::getInstance()->setString("LogLevel", "error");

  Settings::getInstance()->setInt("WindowWidth", WIDTH);
  Settings::getInstance()->setInt("WindowHeight", HEIGHT);
  Settings::getInstance()->setInt("ScreenWidth", WIDTH);
  Settings::getInstance()->setInt("ScreenHeight", HEIGHT);
  Settings::getInstance()->setBool("Windowed", true);
  Settings::getInstance()->setBool("FullscreenBorderless", false);
  return true;
}

void signalHandler(int signum) {
  if (signum == SIGSEGV)
    LOG(LogError) << "Interrupt signal SIGSEGV received.\n";
  else if (signum == SIGFPE)
    LOG(LogError) << "Interrupt signal SIGFPE received.\n";
  else if (signum == SIGFPE)
    LOG(LogError) << "Interrupt signal SIGFPE received.\n";
  else
    LOG(LogError) << "Interrupt signal (" << signum << ") received.\n";

  // cleanup and close up stuff here
  exit(signum);
}

void onExit() { Log::close(); }

int main(int argc, char **argv) {
  signal(SIGFPE, signalHandler);
  signal(SIGILL, signalHandler);
  signal(SIGINT, signalHandler);
  signal(SIGSEGV, signalHandler);
  // signal(SIGABRT, signalHandler);
  // signal(SIGTERM, signalHandler);

  // initialize settings
  parseArgs(argc, argv);
  // Paths::getUserEmulationStationPath() -> ~/.emulationstation

  // start the logger ~/.emulationstation/es_log.txt
  Log::init();
  LOG(LogInfo) << "sdl-station";

  // always close the log on exit
  atexit(&onExit);

  // create window
  Renderer::init();

  int lastTime = SDL_GetTicks();
  int ps_time = SDL_GetTicks();
  bool running = true;

  while (running) {
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {

      switch (ev.type) {

      case SDL_QUIT:
        running = false;
        break;

      case SDL_KEYDOWN:
        if (ev.key.keysym.sym == SDLK_ESCAPE)
          running = false;
        break;

      case SDL_JOYAXISMOTION:
      case SDL_JOYBUTTONDOWN:
      case SDL_JOYBUTTONUP:
        running = false;
        break;
      }
    }

    int curTime = SDL_GetTicks();
    int deltaTime = curTime - lastTime;
    lastTime = curTime;

    // cap deltaTime if it ever goes negative
    if (deltaTime < 0)
      deltaTime = 1000;

    Renderer::drawRect((float)WIDTH / 4, (float)HEIGHT / 4, (float)WIDTH / 2,
                       (float)HEIGHT / 2, 0xFF000033, 0xFF000033);
    Renderer::drawRect((float)WIDTH / 3, (float)HEIGHT / 3, (float)WIDTH / 3,
                       (float)HEIGHT / 3, 0xFF000033, 0xFF000033);
    Renderer::swapBuffers();

    Log::flush();
  }

  // Destroy it
  Renderer::deinit();

  LOG(LogInfo) << "sdl-station cleanly shutting down.";

  return 0;
}
