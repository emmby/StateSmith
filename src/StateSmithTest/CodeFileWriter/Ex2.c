// Autogenerated with StateSmith.
// Algorithm: Balanced2. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#include "Ex2.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(Ex2* sm, Ex2_StateId desired_state);

static void ROOT_enter(Ex2* sm);

static void STATE_1_enter(Ex2* sm);

static void STATE_1_exit(Ex2* sm);

static void STATE_1_do(Ex2* sm);

static void STATE_2_enter(Ex2* sm);

static void STATE_2_exit(Ex2* sm);

static void STATE_2_ev2(Ex2* sm);

static void STATE_2_myev1(Ex2* sm);


// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void Ex2_ctor(Ex2* sm)
{
    memset(sm, 0, sizeof(*sm));
}

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void Ex2_start(Ex2* sm)
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
        // uml: TransitionTo(STATE_1)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `STATE_1`.
            STATE_1_enter(sm);
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            return;
        } // end of behavior for ROOT.<InitialState>
    } // end of behavior for ROOT
}

// Dispatches an event to the state machine. Not thread safe.
// Note! This function assumes that the `event_id` parameter is valid.
void Ex2_dispatch_event(Ex2* sm, Ex2_EventId event_id)
{
    switch (sm->state_id)
    {
        // STATE: Ex2
        case Ex2_StateId_ROOT:
            switch (event_id)
            {
                // Events not handled by this state:
                case Ex2_EventId_DO: break;
                case Ex2_EventId_MYEV1: break;
                case Ex2_EventId_EV2: break;
            }
            break;
        
        // STATE: STATE_1
        case Ex2_StateId_STATE_1:
            switch (event_id)
            {
                case Ex2_EventId_DO: STATE_1_do(sm); break;
                // Events not handled by this state:
                case Ex2_EventId_MYEV1: break;
                case Ex2_EventId_EV2: break;
            }
            break;
        
        // STATE: STATE_2
        case Ex2_StateId_STATE_2:
            switch (event_id)
            {
                case Ex2_EventId_MYEV1: STATE_2_myev1(sm); break;
                case Ex2_EventId_EV2: STATE_2_ev2(sm); break;
                // Events not handled by this state:
                case Ex2_EventId_DO: break;
            }
            break;
    }
    
}

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(Ex2* sm, Ex2_StateId desired_state)
{
    while (sm->state_id != desired_state)
    {
        switch (sm->state_id)
        {
            case Ex2_StateId_STATE_1: STATE_1_exit(sm); break;
            
            case Ex2_StateId_STATE_2: STATE_2_exit(sm); break;
            
            default: return;  // Just to be safe. Prevents infinite loop if state ID memory is somehow corrupted.
        }
    }
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(Ex2* sm)
{
    sm->state_id = Ex2_StateId_ROOT;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state STATE_1
////////////////////////////////////////////////////////////////////////////////

static void STATE_1_enter(Ex2* sm)
{
    sm->state_id = Ex2_StateId_STATE_1;
}

static void STATE_1_exit(Ex2* sm)
{
    sm->state_id = Ex2_StateId_ROOT;
}

static void STATE_1_do(Ex2* sm)
{
    // STATE_1 behavior
    // uml: do TransitionTo(STATE_2)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        STATE_1_exit(sm);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `STATE_2`.
        STATE_2_enter(sm);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        return;
    } // end of behavior for STATE_1
    
    // No ancestor handles this event.
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state STATE_2
////////////////////////////////////////////////////////////////////////////////

static void STATE_2_enter(Ex2* sm)
{
    sm->state_id = Ex2_StateId_STATE_2;
}

static void STATE_2_exit(Ex2* sm)
{
    sm->state_id = Ex2_StateId_ROOT;
}

static void STATE_2_ev2(Ex2* sm)
{
    // STATE_2 behavior
    // uml: EV2 / { stuff(); }
    {
        // Step 1: execute action `stuff();`
        stuff();
    } // end of behavior for STATE_2
    
    // No ancestor handles this event.
}

static void STATE_2_myev1(Ex2* sm)
{
    // STATE_2 behavior
    // uml: myEv1 / { do_stuff(); }
    {
        // Step 1: execute action `do_stuff();`
        do_stuff();
    } // end of behavior for STATE_2
    
    // No ancestor handles this event.
}

// Thread safe.
char const * Ex2_state_id_to_string(Ex2_StateId id)
{
    switch (id)
    {
        case Ex2_StateId_ROOT: return "ROOT";
        case Ex2_StateId_STATE_1: return "STATE_1";
        case Ex2_StateId_STATE_2: return "STATE_2";
        default: return "?";
    }
}

// Thread safe.
char const * Ex2_event_id_to_string(Ex2_EventId id)
{
    switch (id)
    {
        case Ex2_EventId_DO: return "DO";
        case Ex2_EventId_EV2: return "EV2";
        case Ex2_EventId_MYEV1: return "MYEV1";
        default: return "?";
    }
}
// Converts an event id to a string. Thread safe.
const char* Ex2_event_id_to_string(const enum EventId id)
{
    switch (id)
    {
        case DO: return "do";
        case EV2: return "ev2";
        case MYEV1: return "myev1";
    }
    return "?";
}
