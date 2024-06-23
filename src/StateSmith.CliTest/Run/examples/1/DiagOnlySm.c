// Autogenerated with StateSmith 0.10.0-alpha+ab8c57ce711a699bdd49c7944b94ef4dfbf80060.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#include "DiagOnlySm.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(DiagOnlySm* sm, DiagOnlySm_Func desired_state_exit_handler);

static void ROOT_enter(DiagOnlySm* sm);

static void ROOT_exit(DiagOnlySm* sm);

static void STATE_1_enter(DiagOnlySm* sm);

static void STATE_1_exit(DiagOnlySm* sm);

static void STATE_1_do(DiagOnlySm* sm);

static void STATE_1_my_event_1(DiagOnlySm* sm);

static void STATE_2_enter(DiagOnlySm* sm);

static void STATE_2_exit(DiagOnlySm* sm);

static void STATE_2_my_event_2(DiagOnlySm* sm);


// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void DiagOnlySm_ctor(DiagOnlySm* sm)
{
    memset(sm, 0, sizeof(*sm));
}

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void DiagOnlySm_start(DiagOnlySm* sm)
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
            sm->state_id = DiagOnlySm_StateId_STATE_1;
            // No ancestor handles event. Can skip nulling `ancestor_event_handler`.
            return;
        } // end of behavior for ROOT.<InitialState>
    } // end of behavior for ROOT
}

// Dispatches an event to the state machine. Not thread safe.
void DiagOnlySm_dispatch_event(DiagOnlySm* sm, DiagOnlySm_EventId event_id)
{
    DiagOnlySm_Func behavior_func = sm->current_event_handlers[event_id];
    
    while (behavior_func != NULL)
    {
        sm->ancestor_event_handler = NULL;
        behavior_func(sm);
        behavior_func = sm->ancestor_event_handler;
    }
}

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(DiagOnlySm* sm, DiagOnlySm_Func desired_state_exit_handler)
{
    while (sm->current_state_exit_handler != desired_state_exit_handler)
    {
        sm->current_state_exit_handler(sm);
    }
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(DiagOnlySm* sm)
{
    // setup trigger/event handlers
    sm->current_state_exit_handler = ROOT_exit;
}

static void ROOT_exit(DiagOnlySm* sm)
{
    // State machine root is a special case. It cannot be exited. Mark as unused.
    (void)sm;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state STATE_1
////////////////////////////////////////////////////////////////////////////////

static void STATE_1_enter(DiagOnlySm* sm)
{
    // setup trigger/event handlers
    sm->current_state_exit_handler = STATE_1_exit;
    sm->current_event_handlers[DiagOnlySm_EventId_DO] = STATE_1_do;
    sm->current_event_handlers[DiagOnlySm_EventId_MY_EVENT_1] = STATE_1_my_event_1;
    
    // STATE_1 behavior
    // uml: enter / { print("S1 enter"); }
    {
        // Step 1: execute action `print("S1 enter");`
        print("S1 enter");
    } // end of behavior for STATE_1
}

static void STATE_1_exit(DiagOnlySm* sm)
{
    // STATE_1 behavior
    // uml: exit / { print("S1 exit"); }
    {
        // Step 1: execute action `print("S1 exit");`
        print("S1 exit");
    } // end of behavior for STATE_1
    
    // adjust function pointers for this state's exit
    sm->current_state_exit_handler = ROOT_exit;
    sm->current_event_handlers[DiagOnlySm_EventId_DO] = NULL;  // no ancestor listens to this event
    sm->current_event_handlers[DiagOnlySm_EventId_MY_EVENT_1] = NULL;  // no ancestor listens to this event
}

static void STATE_1_do(DiagOnlySm* sm)
{
    // No ancestor state handles `do` event.
    
    // STATE_1 behavior
    // uml: do / { print("S1 do"); }
    {
        // Step 1: execute action `print("S1 do");`
        print("S1 do");
        
        // Step 2: determine if ancestor gets to handle event next.
        // Don't consume special `do` event.
    } // end of behavior for STATE_1
}

static void STATE_1_my_event_1(DiagOnlySm* sm)
{
    // No ancestor state handles `my_event_1` event.
    
    // STATE_1 behavior
    // uml: MY_EVENT_1 TransitionTo(STATE_2)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        STATE_1_exit(sm);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `STATE_2`.
        STATE_2_enter(sm);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        sm->state_id = DiagOnlySm_StateId_STATE_2;
        // No ancestor handles event. Can skip nulling `ancestor_event_handler`.
        return;
    } // end of behavior for STATE_1
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state STATE_2
////////////////////////////////////////////////////////////////////////////////

static void STATE_2_enter(DiagOnlySm* sm)
{
    // setup trigger/event handlers
    sm->current_state_exit_handler = STATE_2_exit;
    sm->current_event_handlers[DiagOnlySm_EventId_MY_EVENT_2] = STATE_2_my_event_2;
    
    // STATE_2 behavior
    // uml: enter / { print("S2 enter"); }
    {
        // Step 1: execute action `print("S2 enter");`
        print("S2 enter");
    } // end of behavior for STATE_2
}

static void STATE_2_exit(DiagOnlySm* sm)
{
    // STATE_2 behavior
    // uml: exit / { print("S2 exit"); }
    {
        // Step 1: execute action `print("S2 exit");`
        print("S2 exit");
    } // end of behavior for STATE_2
    
    // adjust function pointers for this state's exit
    sm->current_state_exit_handler = ROOT_exit;
    sm->current_event_handlers[DiagOnlySm_EventId_MY_EVENT_2] = NULL;  // no ancestor listens to this event
}

static void STATE_2_my_event_2(DiagOnlySm* sm)
{
    // No ancestor state handles `my_event_2` event.
    
    // STATE_2 behavior
    // uml: MY_EVENT_2 TransitionTo(STATE_1)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        STATE_2_exit(sm);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `STATE_1`.
        STATE_1_enter(sm);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        sm->state_id = DiagOnlySm_StateId_STATE_1;
        // No ancestor handles event. Can skip nulling `ancestor_event_handler`.
        return;
    } // end of behavior for STATE_2
}

// Thread safe.
char const * DiagOnlySm_state_id_to_string(DiagOnlySm_StateId id)
{
    switch (id)
    {
        case DiagOnlySm_StateId_ROOT: return "ROOT";
        case DiagOnlySm_StateId_STATE_1: return "STATE_1";
        case DiagOnlySm_StateId_STATE_2: return "STATE_2";
        default: return "?";
    }
}

// Thread safe.
char const * DiagOnlySm_event_id_to_string(DiagOnlySm_EventId id)
{
    switch (id)
    {
        case DiagOnlySm_EventId_DO: return "DO";
        case DiagOnlySm_EventId_MY_EVENT_1: return "MY_EVENT_1";
        case DiagOnlySm_EventId_MY_EVENT_2: return "MY_EVENT_2";
        default: return "?";
    }
}