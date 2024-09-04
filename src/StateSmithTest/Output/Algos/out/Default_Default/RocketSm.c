// Autogenerated with StateSmith.
// Algorithm: Balanced2. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#include "RocketSm.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(RocketSm* sm, RocketSm_StateId desired_state);

static void ROOT_enter(RocketSm* sm);

static void ROOT_exit(RocketSm* sm);

static void C1_enter(RocketSm* sm);

static void C1_exit(RocketSm* sm);


// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void RocketSm_ctor(RocketSm* sm)
{
    memset(sm, 0, sizeof(*sm));
}

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void RocketSm_start(RocketSm* sm)
{
    ROOT_enter(sm);
    // ROOT behavior
    // uml: TransitionTo(ROOT.<InitialState>)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ROOT.<InitialState>`.
        // ROOT.<InitialState> is a pseudo state and cannot have an `enter` trigger.
        
        // ROOT.<InitialState> behavior
        // uml: TransitionTo(c1)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `c1`.
            C1_enter(sm);
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            return;
        } // end of behavior for ROOT.<InitialState>
    } // end of behavior for ROOT
}

// Dispatches an event to the state machine. Not thread safe.
// Note! This function assumes that the `event_id` parameter is valid.
void RocketSm_dispatch_event(RocketSm* sm, RocketSm_EventId event_id)
{
    // This state machine design only has a single event type so we can safely assume
    // that the dispatched event is `do` without checking the `event_id` parameter.
    (void)event_id; // This line prevents an 'unused variable' compiler warning
    
    switch (sm->state_id)
    {
        // STATE: RocketSm
        case RocketSm_StateId_ROOT:
            // state and ancestors have no handler for `do` event.
            break;
        
        // STATE: c1
        case RocketSm_StateId_C1:
            // state and ancestors have no handler for `do` event.
            break;
    }
    
}

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(RocketSm* sm, RocketSm_StateId desired_state)
{
    while (sm->state_id != desired_state)
    {
        switch (sm->state_id)
        {
            case RocketSm_StateId_ROOT: ROOT_exit(sm); break;
            
            case RocketSm_StateId_C1: C1_exit(sm); break;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(RocketSm* sm)
{
    sm->state_id = RocketSm_StateId_ROOT;
}

static void ROOT_exit(RocketSm* sm)
{
    // State machine root is a special case. It cannot be exited. Mark as unused.
    (void)sm;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state C1
////////////////////////////////////////////////////////////////////////////////

static void C1_enter(RocketSm* sm)
{
    sm->state_id = RocketSm_StateId_C1;
}

static void C1_exit(RocketSm* sm)
{
    sm->state_id = RocketSm_StateId_ROOT;
}

// Thread safe.
char const * RocketSm_state_id_to_string(RocketSm_StateId id)
{
    switch (id)
    {
        case RocketSm_StateId_ROOT: return "ROOT";
        case RocketSm_StateId_C1: return "C1";
        default: return "?";
    }
}

// Thread safe.
char const * RocketSm_event_id_to_string(RocketSm_EventId id)
{
    switch (id)
    {
        case RocketSm_EventId_DO: return "DO";
        default: return "?";
    }
}
