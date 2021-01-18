//
// Created by lezenn on 18/01/2021.
//

#include "Application.hpp"
#include <SDL2/SDL.h>
#include <stdexcept>
#include "Logger.hpp"

namespace quazar::core
{

    Application::Application(const std::string& name, int width, int height) noexcept
        : m_main_window {name, width, height}
    {
    }

    void Application::Init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::string message = std::string("Failed to initialize SDL Video.\n") + SDL_GetError();
            Logger::error(message);
            throw std::runtime_error(message);
        }

        m_main_window.Init();
    }

    void Application::Run()
    {
        auto screenSurface = m_main_window.GetSurface();
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
        m_main_window.UpdateSurface();
        SDL_Delay(2000);
    }

    Application::~Application()
    {
        SDL_Quit();
    }

    Window &Application::GetWindow() noexcept
    {
        return m_main_window;
    }
}