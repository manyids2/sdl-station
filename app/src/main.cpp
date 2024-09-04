#include "Log.h"
#include "Paths.h"
#include "SDL_events.h"
#include "SDL_timer.h"
#include "Settings.h"
#include "renderers/Renderer.h"
// #include "renderers/Renderer.h"
#include <csignal>
#include <iostream>

bool parseArgs(int argc, char *argv[]) {
  // We need to process --home before any call to Settings::getInstance(),
  // because settings are loaded from homepath
  Paths::setExePath(argv[0]);
  Settings::getInstance();

  int width, height;
  width = 1280;
  height = 720;

  // Paths::setHomePath(home);

  // Settings that are accessed from parseArgs:

  Settings::getInstance()->setString("LogLevel", "debug");
  // Settings::getInstance()->setInt("MonitorID", monitorId);

  Settings::getInstance()->setInt("WindowWidth", width);
  Settings::getInstance()->setInt("WindowHeight", height);
  Settings::getInstance()->setBool("FullscreenBorderless", false);

  Settings::getInstance()->setInt("ScreenWidth", width);
  Settings::getInstance()->setInt("ScreenHeight", height);

  Settings::getInstance()->setInt("ScreenOffsetX", 0);
  Settings::getInstance()->setInt("ScreenOffsetY", 0);

  Settings::getInstance()->setInt("ScreenRotate", 0);
  // Settings::getInstance()->setBool("ParseGamelistOnly", true);
  // Settings::getInstance()->setBool("IgnoreGamelist", true);
  // Settings::getInstance()->setBool("DrawFramerate", true);
  // Settings::getInstance()->setBool("ShowExit", false);
  // Settings::getInstance()->setBool("ExitOnRebootRequired", true);
  // Settings::getInstance()->setBool("SplashScreen", false);
  // Settings::getInstance()->setString("AlternateSplashScreen", argv[i + 1]);
  // Settings::getInstance()->setBool("Debug", true);
  // Settings::getInstance()->setBool("HideConsole", false);
  // Settings::getInstance()->setBool("FullscreenBorderless", true);
  // Settings::getInstance()->setBool("FullscreenBorderless", false);
  Settings::getInstance()->setBool("Windowed", true);
  // Settings::getInstance()->setBool("VSync", vsync);
  // Settings::getInstance()->setInt("MaxVRAM", maxVRAM);
  // Settings::getInstance()->setBool("ForceKiosk", true);
  // Settings::getInstance()->setBool("ForceKid", true);
  // Settings::getInstance()->setBool("ForceDisableFilters", true);
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
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      // if (event.type == SDL_QUIT)
      running = false;
    }

    int curTime = SDL_GetTicks();
    int deltaTime = curTime - lastTime;
    lastTime = curTime;

    // cap deltaTime if it ever goes negative
    if (deltaTime < 0)
      deltaTime = 1000;

    Renderer::swapBuffers();

    Log::flush();
  }

  // Destroy it
  Renderer::deinit();

  LOG(LogInfo) << "sdl-station cleanly shutting down.";

  return 0;
}
