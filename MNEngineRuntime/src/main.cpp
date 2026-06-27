#include "MNEngineCore/Core.hpp"
#include "MNEngineCore/Window.hpp"
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    auto sdlGuard = MNEngine::Core::Initialize(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (!sdlGuard)
        return -1;

    MNEngine::Window window("MNEngine Sandbox", 1280, 720, SDL_WINDOW_RESIZABLE);

    using Clock = std::chrono::high_resolution_clock;
    auto lastTime = Clock::now();

    while (window.IsRunning())
    {
        auto currentTime = Clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - lastTime;
        lastTime = currentTime;
        float deltaTime = elapsedTime.count();

        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        window.ProcessEvents();

        window.Clear();

        window.Present();
    }

    return 0;
}
