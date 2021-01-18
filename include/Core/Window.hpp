//
// Created by lezenn on 18/01/2021.
//

#ifndef QUAZAR_WINDOW_HPP
#define QUAZAR_WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>

namespace quazar::core
{
    class Window
    {
    public:

        Window(const std::string& name, int width, int height) noexcept;
        ~Window();

        void Init();
        void UpdateSurface();

        const std::string& GetName() const noexcept;
        int GetWidth() const noexcept;
        int GetHeight() const noexcept;
        SDL_Surface* GetSurface() const noexcept;
        SDL_Window* GetWindow() const noexcept;

    private:
        std::string m_name;
        int m_width, m_height;

        SDL_Surface* m_surface;
        SDL_Window* m_window;

        bool m_initialized;
    };
}

#endif //QUAZAR_WINDOW_HPP
