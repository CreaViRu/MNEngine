#include "MNEngineCore/Window.hpp"

namespace MNEngine
{

    Window::Window(std::string_view title, int width, int height, SDL_WindowFlags flags)
    {
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;

        if (!SDL_CreateWindowAndRenderer(title.data(), width, height, flags, &window, &renderer))
        {
            SDL_Log("Failed to create Window/Renderer: %s", SDL_GetError());
            m_isRunning = false;
            return;
        }

        m_window.reset(window);
        m_renderer.reset(renderer);
    }

    void Window::ProcessEvents() noexcept
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                m_isRunning = false;
            }
        }
    }

    void Window::Clear() noexcept
    {
        SDL_SetRenderDrawColor(m_renderer.get(), 20, 20, 20, 255); // Темно-серый фон
        SDL_RenderClear(m_renderer.get());
    }

    void Window::Present() noexcept
    {
        SDL_RenderPresent(m_renderer.get());
    }

}
