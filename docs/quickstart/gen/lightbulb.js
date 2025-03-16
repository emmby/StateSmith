// Autogenerated with StateSmith 0.17.2+f00a1b3574678a22b8325a2a514645743cbe36e2.
// Algorithm: Balanced2. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

// Generated state machine
class lightbulb
{
    static EventId = 
    {
        SWITCH : 0,
    }
    static { Object.freeze(this.EventId); }
    
    static EventIdCount = 1;
    static { Object.freeze(this.EventIdCount); }
    
    static StateId = 
    {
        ROOT : 0,
        OFF : 1,
        ON : 2,
    }
    static { Object.freeze(this.StateId); }
    
    static StateIdCount = 3;
    static { Object.freeze(this.StateIdCount); }
    
    // Used internally by state machine. Feel free to inspect, but don't modify.
    stateId;
    
    // Starts the state machine. Must be called before dispatching events. Not thread safe.
    start()
    {
        this.#ROOT_enter();
        // ROOT behavior
        // uml: TransitionTo(ROOT.<InitialState>)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `ROOT.<InitialState>`.
            // ROOT.<InitialState> is a pseudo state and cannot have an `enter` trigger.
            
            // ROOT.<InitialState> behavior
            // uml: TransitionTo(Off)
            {
                // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
                
                // Step 2: Transition action: ``.
                
                // Step 3: Enter/move towards transition target `Off`.
                this.#OFF_enter();
                
                // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
                return;
            } // end of behavior for ROOT.<InitialState>
        } // end of behavior for ROOT
    }
    
    // Dispatches an event to the state machine. Not thread safe.
    // Note! This function assumes that the `eventId` parameter is valid.
    dispatchEvent(eventId)
    {
        
        switch (this.stateId)
        {
            // STATE: lightbulb
            case lightbulb.StateId.ROOT:
                // state and ancestors have no handler for `switch` event.
                break;
            
            // STATE: Off
            case lightbulb.StateId.OFF:
                this.#OFF_switch(); 
                break;
            
            // STATE: On
            case lightbulb.StateId.ON:
                this.#ON_switch(); 
                break;
        }
        
    }
    
    // This function is used when StateSmith doesn't know what the active leaf state is at
    // compile time due to sub states or when multiple states need to be exited.
    #exitUpToStateHandler(desiredState)
    {
        while (this.stateId != desiredState)
        {
            switch (this.stateId)
            {
                case lightbulb.StateId.OFF: this.#OFF_exit(); break;
                
                case lightbulb.StateId.ON: this.#ON_exit(); break;
                
                default: return;  // Just to be safe. Prevents infinite loop if state ID memory is somehow corrupted.
            }
        }
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state ROOT
    ////////////////////////////////////////////////////////////////////////////////
    
    #ROOT_enter()
    {
        this.stateId = lightbulb.StateId.ROOT;
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state OFF
    ////////////////////////////////////////////////////////////////////////////////
    
    #OFF_enter()
    {
        this.stateId = lightbulb.StateId.OFF;
    }
    
    #OFF_exit()
    {
        this.stateId = lightbulb.StateId.ROOT;
    }
    
    #OFF_switch()
    {
        // Off behavior
        // uml: Switch TransitionTo(On)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
            this.#OFF_exit();
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `On`.
            this.#ON_enter();
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            return;
        } // end of behavior for Off
        
        // No ancestor handles this event.
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state ON
    ////////////////////////////////////////////////////////////////////////////////
    
    #ON_enter()
    {
        this.stateId = lightbulb.StateId.ON;
    }
    
    #ON_exit()
    {
        this.stateId = lightbulb.StateId.ROOT;
    }
    
    #ON_switch()
    {
        // On behavior
        // uml: Switch TransitionTo(Off)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
            this.#ON_exit();
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `Off`.
            this.#OFF_enter();
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            return;
        } // end of behavior for On
        
        // No ancestor handles this event.
    }
    
    // Thread safe.
    static stateIdToString(id)
    {
        switch (id)
        {
            case lightbulb.StateId.ROOT: return "ROOT";
            case lightbulb.StateId.OFF: return "OFF";
            case lightbulb.StateId.ON: return "ON";
            default: return "?";
        }
    }
    
    // Thread safe.
    static eventIdToString(id)
    {
        switch (id)
        {
            case lightbulb.EventId.SWITCH: return "SWITCH";
            default: return "?";
        }
    }
}
