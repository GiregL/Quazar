//
// Created by lezenn on 18/01/2021.
//

#ifndef QUAZAR_APPLICATION_HPP
#define QUAZAR_APPLICATION_HPP

#include <memory>
#include "Window.hpp"

namespace quazar::core
{
    class Application
    {
    public:

        Application(const std::string& name, int width, int height) noexcept;

        void Init();
        void Run();

        ~Application();

        Window& GetWindow() noexcept;

    private:
        Window m_main_window;

    };
}

#endif //QUAZAR_APPLICATION_HPP
