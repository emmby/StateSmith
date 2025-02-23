// Autogenerated with StateSmith 0.17.3+594ad33398ce411f61e512b23481f63147af5845.
// Algorithm: Balanced2. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#pragma once  // You can also specify normal include guard. See https://github.com/StateSmith/StateSmith/blob/main/docs/settings.md
#include <stdint.h>

typedef enum lightbulb_EventId
{
    lightbulb_EventId_SWITCH = 0
} lightbulb_EventId;

enum
{
    lightbulb_EventIdCount = 1
};

typedef enum lightbulb_StateId
{
    lightbulb_StateId_ROOT = 0,
    lightbulb_StateId_OFF = 1,
    lightbulb_StateId_ON = 2
} lightbulb_StateId;

enum
{
    lightbulb_StateIdCount = 3
};


// Generated state machine
// forward declaration
typedef struct lightbulb lightbulb;

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void lightbulb_ctor(lightbulb* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void lightbulb_start(lightbulb* sm);

// Dispatches an event to the state machine. Not thread safe.
// Note! This function assumes that the `event_id` parameter is valid.
void lightbulb_dispatch_event(lightbulb* sm, lightbulb_EventId event_id);

// Thread safe.
char const * lightbulb_state_id_to_string(lightbulb_StateId id);

// Thread safe.
char const * lightbulb_event_id_to_string(lightbulb_EventId id);

// Generated state machine
struct lightbulb
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    lightbulb_StateId state_id;
};

