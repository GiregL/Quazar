//
// Created by lezenn on 18/01/2021.
//

#ifndef QUAZAR_EVENTTYPE_HPP
#define QUAZAR_EVENTTYPE_HPP

#include <SDL2/SDL.h>
#include <unordered_map>

namespace quazar::core
{
    enum class EventType
    {
        QuitEvent,
        UnHandledEvent
    };

    EventType FromSDLEventType(Uint32 type);
}

#endif //QUAZAR_EVENTTYPE_HPP
