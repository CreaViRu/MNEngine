#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <string_view>

namespace MNEngine
{
    struct WindowDeleter
    {
        void operator()(SDL_Window *w) const { SDL_DestroyWindow(w); }
    };

    struct RendererDeleter
    {
        void operator()(SDL_Renderer *r) const { SDL_DestroyRenderer(r); }
    };

    using WindowPtr = std::unique_ptr<SDL_Window, WindowDeleter>;
    using RendererPtr = std::unique_ptr<SDL_Renderer, RendererDeleter>;

    class Window
    {
    public:
        Window(std::string_view title, int width, int height, SDL_WindowFlags flags);
        ~Window() = default;

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;
        Window(Window &&) noexcept = default;
        Window &operator=(Window &&) noexcept = default;

        [[nodiscard]] bool IsRunning() const noexcept { return m_isRunning; }
        void ProcessEvents() noexcept;

        void Clear() noexcept;
        void Present() noexcept;

        [[nodiscard]] SDL_Renderer *GetRenderer() const noexcept { return m_renderer.get(); }

    private:
        WindowPtr m_window{nullptr};
        RendererPtr m_renderer{nullptr};
        bool m_isRunning{true};
    };

}
