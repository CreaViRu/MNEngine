#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <chrono>

namespace MNEngine
{
    struct SDLDeleter
    {
        void operator()(bool *initialized) const
        {
            if (initialized && *initialized)
            {
                SDL_Quit();
                delete initialized;
            }
        }
    };

    template <typename T>
    concept GameSystem = requires(T system, float deltaTime) {
        { system.Init() } -> std::same_as<bool>;
        { system.Update(deltaTime) } -> std::same_as<void>;
        { system.Render() } -> std::same_as<void>;
        { system.Shutdown() } -> std::same_as<void>;
    };

    class Core
    {
    public:
        static [[nodiscard]] std::unique_ptr<bool, SDLDeleter> Initialize(Uint32 flags)
        {
            if (!SDL_Init(flags))
            {
                SDL_Log("SDL Init Failed: %s", SDL_GetError());
                return nullptr;
            }
            return std::unique_ptr<bool, SDLDeleter>(new bool(true));
        }
    };

}
