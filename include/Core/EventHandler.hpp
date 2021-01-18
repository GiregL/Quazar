//
// Created by lezenn on 18/01/2021.
//

#ifndef QUAZAR_EVENTHANDLER_HPP
#define QUAZAR_EVENTHANDLER_HPP

#include <SDL2/SDL.h>
#include <functional>

#include "EventType.hpp"

namespace quazar::core
{
    class Application;

    using Handler = std::function<void(Application&)>;

    class EventHandler
    {
    public:
        EventHandler(const EventType&, Handler);

        bool Matches(const EventType&) const;

        void Run(const EventType&, Application& app);

    private:
        EventType m_event_type;
        Handler m_function;
    };
}

#endif //QUAZAR_EVENTHANDLER_HPP
