//
// Created by lezenn on 18/01/2021.
//

#ifndef QUAZAR_APPLICATION_HPP
#define QUAZAR_APPLICATION_HPP

#include <memory>
#include <vector>
#include "Window.hpp"
#include "EventType.hpp"
#include "EventHandler.hpp"

namespace quazar::core
{
    class Application
    {
    public:

        Application(const std::string& name, int width, int height) noexcept;

        void Init();
        void Run();

        void AddEventHandler(EventHandler&& handler) noexcept;
        void AddEventHandler(EventType type, Handler handler) noexcept;

        ~Application();

        void SetRunning(bool run) noexcept;

        Window& GetWindow() noexcept;
        bool IsRunning() const noexcept;

    private:
        Window m_main_window;
        bool m_is_running;
        std::vector<EventHandler> m_event_handlers;
    };
}

#endif //QUAZAR_APPLICATION_HPP
