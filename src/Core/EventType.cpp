//
// Created by lezenn on 18/01/2021.
//

#include "EventType.hpp"
#include <SDL2/SDL.h>

namespace quazar::core
{
    EventType FromSDLEventType(Uint32 type)
    {
        switch (type)
        {
            case SDL_QUIT:
                return EventType::QuitEvent;
            default:
                return EventType::UnHandledEvent;
        }
    }
}