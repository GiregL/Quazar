//
// Created by lezenn on 18/01/2021.
//

#include "Window.hpp"
#include <stdexcept>

namespace quazar::core
{
    Window::Window(const std::string& name, int width, int height) noexcept
        : m_name {name}
        , m_width {width}
        , m_height {height}
        , m_initialized {false}
        , m_surface {nullptr}
        , m_window {nullptr}
    {
    }

    void Window::Init()
    {
        m_window = SDL_CreateWindow(
                m_name.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                m_width, m_height,
                SDL_WINDOW_SHOWN);
        if (!m_window)
        {
            throw std::runtime_error(std::string("Failed to initialize window named : ") + m_name);
        }
        m_initialized = true;
        m_surface = SDL_GetWindowSurface(m_window);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }

    const std::string& Window::GetName() const noexcept
    {
        return m_name;
    }

    int Window::GetHeight() const noexcept
    {
        return m_height;
    }

    int Window::GetWidth() const noexcept
    {
        return m_width;
    }

    SDL_Window* Window::GetWindow() const noexcept
    {
        return m_window;
    }

    SDL_Surface* Window::GetSurface() const noexcept
    {
        return m_surface;
    }

    void Window::UpdateSurface()
    {
        SDL_UpdateWindowSurface(m_window);
    }
}