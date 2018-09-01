#pragma once

#include "Singleton.h"


class DebugManager : public Singleton<DebugManager>
{
public:
    void init();
    void receive(const struct KeyPressedEvent& event);
    void receive(const struct KeyReleasedEvent& event);
    void receive(const struct MouseMovedEvent& event);
    void receive(const struct MoveEvent& event);
};
