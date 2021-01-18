//
// Created by lezenn on 18/01/2021.
//

#include "EventHandler.hpp"

#include <utility>
#include "Application.hpp"

namespace quazar::core
{

    EventHandler::EventHandler(const EventType& type, Handler func)
        : m_event_type {type}
        , m_function {std::move(func)}
    {
    }

    bool EventHandler::Matches(const EventType& type) const
    {
        return m_event_type == type;
    }

    void EventHandler::Run(const EventType& type, Application& app)
    {
        if (!Matches(type)) return;
        m_function(app);
    }
}