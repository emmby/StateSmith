// Autogenerated with StateSmith.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#include "Spec1Sm.h"
#include "../../lang-helpers/c/helper.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

// This function is used when StateSmith doesn't know what the active leaf state is at
// compile time due to sub states or when multiple states need to be exited.
static void exit_up_to_state_handler(Spec1Sm* sm, Spec1Sm_Func desired_state_exit_handler);

static void ROOT_enter(Spec1Sm* sm);

static void ROOT_exit(Spec1Sm* sm);

static void S_enter(Spec1Sm* sm);

static void S_exit(Spec1Sm* sm);

static void S1_enter(Spec1Sm* sm);

static void S1_exit(Spec1Sm* sm);

static void S1_InitialState_transition(Spec1Sm* sm);

static void S11_enter(Spec1Sm* sm);

static void S11_exit(Spec1Sm* sm);

static void S11_ev1(Spec1Sm* sm);

static void T1_enter(Spec1Sm* sm);

static void T1_exit(Spec1Sm* sm);

static void T11_enter(Spec1Sm* sm);

static void T11_exit(Spec1Sm* sm);

static void T11_ev2(Spec1Sm* sm);

static void T111_enter(Spec1Sm* sm);

static void T111_exit(Spec1Sm* sm);

        
        void Spec1Sm_EventContext_ctor(Spec1Sm_EventContext* sm)
        {
    memset(sm, 0, sizeof(*sm));
        }
    
    // State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
    void Spec1Sm_ctor(Spec1Sm* sm)
    {
    memset(sm, 0, sizeof(*sm));
    }
    
    // Starts the state machine. Must be called before dispatching events. Not thread safe.
    void Spec1Sm_start(Spec1Sm* sm)
    {
        ROOT_enter(sm);
        // ROOT behavior
        // uml: TransitionTo(ROOT.InitialState)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `ROOT.InitialState`.
            // ROOT.InitialState is a pseudo state and cannot have an `enter` trigger.
            
            // ROOT.InitialState behavior
            // uml: / { trace("Transition action `` for ROOT.InitialState to S."); } TransitionTo(S)
            {
                // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
                
                // Step 2: Transition action: `trace("Transition action `` for ROOT.InitialState to S.");`.
                trace("Transition action `` for ROOT.InitialState to S.");
                
                // Step 3: Enter/move towards transition target `S`.
                S_enter(sm);
                
                // S.InitialState behavior
                // uml: / { trace("Transition action `` for S.InitialState to S1."); } TransitionTo(S1)
                {
                    // Step 1: Exit states until we reach `S` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
                    
                    // Step 2: Transition action: `trace("Transition action `` for S.InitialState to S1.");`.
                    trace("Transition action `` for S.InitialState to S1.");
                    
                    // Step 3: Enter/move towards transition target `S1`.
                    S1_enter(sm);
                    
                    // Finish transition by calling pseudo state transition function.
                    S1_InitialState_transition(sm);
                    return; // event processing immediately stops when a transition finishes. No other behaviors for this state are checked.
                } // end of behavior for S.InitialState
            } // end of behavior for ROOT.InitialState
        } // end of behavior for ROOT
    }
    
    // Dispatches an event to the state machine. Not thread safe.
    Spec1Sm_ResultId Spec1Sm_dispatch_event(Spec1Sm* sm, Spec1Sm_EventId event_id)
    {
        if (event_id < 0 || event_id >= (int32_t)Spec1Sm_EventIdCount) return Spec1Sm_ResultId_INVALID;
        Spec1Sm_Func behavior_func = sm->current_event_handlers[event_id];
        
        while (behavior_func != NULL)
        {
            sm->ancestor_event_handler = NULL;
            behavior_func(sm);
            behavior_func = sm->ancestor_event_handler;
        }
        return Spec1Sm_ResultId_CONSUMED; // FIXME finish here!
    }
    
    // This function is used when StateSmith doesn't know what the active leaf state is at
    // compile time due to sub states or when multiple states need to be exited.
    static void exit_up_to_state_handler(Spec1Sm* sm, Spec1Sm_Func desired_state_exit_handler)
    {
        while (sm->current_state_exit_handler != desired_state_exit_handler)
        {
            sm->current_state_exit_handler(sm);
        }
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state ROOT
    ////////////////////////////////////////////////////////////////////////////////
    
    static void ROOT_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = ROOT_exit;
        
        // ROOT behavior
        // uml: enter / { trace("Enter Spec1Sm."); }
        {
            // Step 1: execute action `trace("Enter Spec1Sm.");`
            trace("Enter Spec1Sm.");
        } // end of behavior for ROOT
    }
    
    static void ROOT_exit(Spec1Sm* sm)
    {
        // ROOT behavior
        // uml: exit / { trace("Exit Spec1Sm."); }
        {
            // Step 1: execute action `trace("Exit Spec1Sm.");`
            trace("Exit Spec1Sm.");
        } // end of behavior for ROOT
        
        // State machine root is a special case. It cannot be exited. Mark as unused.
        (void)sm;
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state S
    ////////////////////////////////////////////////////////////////////////////////
    
    static void S_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = S_exit;
        
        // S behavior
        // uml: enter / { trace("Enter S."); }
        {
            // Step 1: execute action `trace("Enter S.");`
            trace("Enter S.");
        } // end of behavior for S
    }
    
    static void S_exit(Spec1Sm* sm)
    {
        // S behavior
        // uml: exit / { trace("Exit S."); }
        {
            // Step 1: execute action `trace("Exit S.");`
            trace("Exit S.");
        } // end of behavior for S
        
        // adjust function pointers for this state's exit
        sm->current_state_exit_handler = ROOT_exit;
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state S1
    ////////////////////////////////////////////////////////////////////////////////
    
    static void S1_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = S1_exit;
        
        // S1 behavior
        // uml: enter / { trace("Enter S1."); }
        {
            // Step 1: execute action `trace("Enter S1.");`
            trace("Enter S1.");
        } // end of behavior for S1
    }
    
    static void S1_exit(Spec1Sm* sm)
    {
        // S1 behavior
        // uml: exit / { trace("Exit S1."); }
        {
            // Step 1: execute action `trace("Exit S1.");`
            trace("Exit S1.");
        } // end of behavior for S1
        
        // adjust function pointers for this state's exit
        sm->current_state_exit_handler = S_exit;
    }
    
    static void S1_InitialState_transition(Spec1Sm* sm)
    {
        // S1.InitialState behavior
        // uml: / { trace("Transition action `` for S1.InitialState to S11."); } TransitionTo(S11)
        {
            // Step 1: Exit states until we reach `S1` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: `trace("Transition action `` for S1.InitialState to S11.");`.
            trace("Transition action `` for S1.InitialState to S11.");
            
            // Step 3: Enter/move towards transition target `S11`.
            S11_enter(sm);
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            sm->state_id = Spec1Sm_StateId_S11;
            sm->ancestor_event_handler = NULL;
            return;
        } // end of behavior for S1.InitialState
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state S11
    ////////////////////////////////////////////////////////////////////////////////
    
    static void S11_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = S11_exit;
        sm->current_event_handlers[Spec1Sm_EventId_EV1] = S11_ev1;
        
        // S11 behavior
        // uml: enter / { trace("Enter S11."); }
        {
            // Step 1: execute action `trace("Enter S11.");`
            trace("Enter S11.");
        } // end of behavior for S11
    }
    
    static void S11_exit(Spec1Sm* sm)
    {
        // S11 behavior
        // uml: exit / { trace("Exit S11."); }
        {
            // Step 1: execute action `trace("Exit S11.");`
            trace("Exit S11.");
        } // end of behavior for S11
        
        // adjust function pointers for this state's exit
        sm->current_state_exit_handler = S1_exit;
        sm->current_event_handlers[Spec1Sm_EventId_EV1] = NULL;  // no ancestor listens to this event
    }
    
    static void S11_ev1(Spec1Sm* sm)
    {
        // No ancestor state handles `ev1` event.
        
        // S11 behavior
        // uml: EV1 [trace_guard("State S11: check behavior `EV1 TransitionTo(S1.ExitPoint(1))`.", true)] / { trace("Transition action `` for S11 to S1.ExitPoint(1)."); } TransitionTo(S1.ExitPoint(1))
        if (trace_guard("State S11: check behavior `EV1 TransitionTo(S1.ExitPoint(1))`.", true))
        {
            // Step 1: Exit states until we reach `S1` state (Least Common Ancestor for transition).
            S11_exit(sm);
            
            // Step 2: Transition action: `trace("Transition action `` for S11 to S1.ExitPoint(1).");`.
            trace("Transition action `` for S11 to S1.ExitPoint(1).");
            
            // Step 3: Enter/move towards transition target `S1.ExitPoint(1)`.
            // S1.ExitPoint(1) is a pseudo state and cannot have an `enter` trigger.
            
            // S1.ExitPoint(1) behavior
            // uml: / { trace("Transition action `` for S1.ExitPoint(1) to T11.EntryPoint(1)."); } TransitionTo(T11.EntryPoint(1))
            {
                // Step 1: Exit states until we reach `S` state (Least Common Ancestor for transition).
                S1_exit(sm);
                
                // Step 2: Transition action: `trace("Transition action `` for S1.ExitPoint(1) to T11.EntryPoint(1).");`.
                trace("Transition action `` for S1.ExitPoint(1) to T11.EntryPoint(1).");
                
                // Step 3: Enter/move towards transition target `T11.EntryPoint(1)`.
                T1_enter(sm);
                T11_enter(sm);
                // T11.EntryPoint(1) is a pseudo state and cannot have an `enter` trigger.
                
                // T11.EntryPoint(1) behavior
                // uml: / { trace("Transition action `` for T11.EntryPoint(1) to T111."); } TransitionTo(T111)
                {
                    // Step 1: Exit states until we reach `T11` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
                    
                    // Step 2: Transition action: `trace("Transition action `` for T11.EntryPoint(1) to T111.");`.
                    trace("Transition action `` for T11.EntryPoint(1) to T111.");
                    
                    // Step 3: Enter/move towards transition target `T111`.
                    T111_enter(sm);
                    
                    // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
                    sm->state_id = Spec1Sm_StateId_T111;
                    // No ancestor handles event. Can skip nulling `ancestor_event_handler`.
                    return;
                } // end of behavior for T11.EntryPoint(1)
            } // end of behavior for S1.ExitPoint(1)
        } // end of behavior for S11
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state T1
    ////////////////////////////////////////////////////////////////////////////////
    
    static void T1_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = T1_exit;
        
        // T1 behavior
        // uml: enter / { trace("Enter T1."); }
        {
            // Step 1: execute action `trace("Enter T1.");`
            trace("Enter T1.");
        } // end of behavior for T1
    }
    
    static void T1_exit(Spec1Sm* sm)
    {
        // T1 behavior
        // uml: exit / { trace("Exit T1."); }
        {
            // Step 1: execute action `trace("Exit T1.");`
            trace("Exit T1.");
        } // end of behavior for T1
        
        // adjust function pointers for this state's exit
        sm->current_state_exit_handler = S_exit;
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state T11
    ////////////////////////////////////////////////////////////////////////////////
    
    static void T11_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = T11_exit;
        sm->current_event_handlers[Spec1Sm_EventId_EV2] = T11_ev2;
        
        // T11 behavior
        // uml: enter / { trace("Enter T11."); }
        {
            // Step 1: execute action `trace("Enter T11.");`
            trace("Enter T11.");
        } // end of behavior for T11
    }
    
    static void T11_exit(Spec1Sm* sm)
    {
        // T11 behavior
        // uml: exit / { trace("Exit T11."); }
        {
            // Step 1: execute action `trace("Exit T11.");`
            trace("Exit T11.");
        } // end of behavior for T11
        
        // adjust function pointers for this state's exit
        sm->current_state_exit_handler = T1_exit;
        sm->current_event_handlers[Spec1Sm_EventId_EV2] = NULL;  // no ancestor listens to this event
    }
    
    static void T11_ev2(Spec1Sm* sm)
    {
        // No ancestor state handles `ev2` event.
        
        // T11 behavior
        // uml: EV2 [trace_guard("State T11: check behavior `EV2 TransitionTo(S1)`.", true)] / { trace("Transition action `` for T11 to S1."); } TransitionTo(S1)
        if (trace_guard("State T11: check behavior `EV2 TransitionTo(S1)`.", true))
        {
            // Step 1: Exit states until we reach `S` state (Least Common Ancestor for transition).
            exit_up_to_state_handler(sm, S_exit);
            
            // Step 2: Transition action: `trace("Transition action `` for T11 to S1.");`.
            trace("Transition action `` for T11 to S1.");
            
            // Step 3: Enter/move towards transition target `S1`.
            S1_enter(sm);
            
            // Finish transition by calling pseudo state transition function.
            S1_InitialState_transition(sm);
            return; // event processing immediately stops when a transition finishes. No other behaviors for this state are checked.
        } // end of behavior for T11
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state T111
    ////////////////////////////////////////////////////////////////////////////////
    
    static void T111_enter(Spec1Sm* sm)
    {
        // setup trigger/event handlers
        sm->current_state_exit_handler = T111_exit;
        
        // T111 behavior
        // uml: enter / { trace("Enter T111."); }
        {
            // Step 1: execute action `trace("Enter T111.");`
            trace("Enter T111.");
        } // end of behavior for T111
    }
    
    static void T111_exit(Spec1Sm* sm)
    {
        // T111 behavior
        // uml: exit / { trace("Exit T111."); }
        {
            // Step 1: execute action `trace("Exit T111.");`
            trace("Exit T111.");
        } // end of behavior for T111
        
        // adjust function pointers for this state's exit
        sm->current_state_exit_handler = T11_exit;
    }
    
    // Thread safe.
    char const * Spec1Sm_state_id_to_string(Spec1Sm_StateId id)
    {
        switch (id)
        {
            case Spec1Sm_StateId_ROOT: return "ROOT";
            case Spec1Sm_StateId_S: return "S";
            case Spec1Sm_StateId_S1: return "S1";
            case Spec1Sm_StateId_S11: return "S11";
            case Spec1Sm_StateId_T1: return "T1";
            case Spec1Sm_StateId_T11: return "T11";
            case Spec1Sm_StateId_T111: return "T111";
            default: return "?";
        }
    }
    
    // Thread safe.
    char const * Spec1Sm_event_id_to_string(Spec1Sm_EventId id)
    {
        switch (id)
        {
            case Spec1Sm_EventId_EV1: return "EV1";
            case Spec1Sm_EventId_EV2: return "EV2";
            default: return "?";
        }
    }
