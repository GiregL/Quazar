//
// Created by lezenn on 18/01/2021.
//

#include <SDL2/SDL.h>
#include <stdexcept>
#include <utility>

#include "Application.hpp"
#include "Logger.hpp"
#include "EventType.hpp"


namespace quazar::core
{

    Application::Application(const std::string& name, int width, int height) noexcept
        : m_main_window {name, width, height}
        , m_is_running {true}
        , m_event_handlers {}
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
        SDL_Event event;
        while (m_is_running)
        {
            while (SDL_PollEvent(&event))
            {
                for (auto& handler : m_event_handlers)
                {
                    handler.Run(FromSDLEventType(event.type), *this);
                }
            }
        }
    }

    Application::~Application()
    {
        SDL_Quit();
    }

    Window &Application::GetWindow() noexcept
    {
        return m_main_window;
    }

    void Application::AddEventHandler(EventHandler &&handler) noexcept
    {
        m_event_handlers.push_back(std::move(handler));
    }

    void Application::AddEventHandler(EventType type, Handler handler) noexcept
    {
        AddEventHandler(EventHandler {type, std::move(handler)});
    }

    void Application::SetRunning(bool run) noexcept
    {
        m_is_running = run;
    }

    bool Application::IsRunning() const noexcept
    {
        return m_is_running;
    }
}