// Autogenerated with StateSmith.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#nullable enable

// Generated state machine
public partial class RocketSm
{
    public enum EventId
    {
        DO = 0, // The `do` event is special. State event handlers do not consume this event (ancestors all get it too) unless a transition occurs.
    }

    public const int EventIdCount = 1;

    public enum StateId
    {
        ROOT = 0,
        C1 = 1,
    }

    public const int StateIdCount = 2;

    // event handler type
    private delegate void Func(RocketSm sm);

    // Used internally by state machine. Feel free to inspect, but don't modify.
    public StateId stateId;

    // Used internally by state machine. Don't modify.
    private Func? ancestorEventHandler;

    // Used internally by state machine. Don't modify.
    private readonly Func?[] currentEventHandlers = new Func[EventIdCount];

    // Used internally by state machine. Don't modify.
    private Func? currentStateExitHandler;

    // State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
    public RocketSm()
    {
    }

    // Starts the state machine. Must be called before dispatching events. Not thread safe.
    public void Start()
    {
        ROOT_enter();
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
                C1_enter();

                // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
                this.stateId = StateId.C1;
                // No ancestor handles event. Can skip nulling `ancestorEventHandler`.
                return;
            } // end of behavior for ROOT.<InitialState>
        } // end of behavior for ROOT
    }

    // Dispatches an event to the state machine. Not thread safe.
    // Note! This function assumes that the `eventId` parameter is valid.
    public void DispatchEvent(EventId eventId)
    {
        Func? behaviorFunc = this.currentEventHandlers[(int)eventId];

        while (behaviorFunc != null)
        {
            this.ancestorEventHandler = null;
            behaviorFunc(this);
            behaviorFunc = this.ancestorEventHandler;
        }
    }

    // This function is used when StateSmith doesn't know what the active leaf state is at
    // compile time due to sub states or when multiple states need to be exited.
    private void ExitUpToStateHandler(Func desiredStateExitHandler)
    {
        while (this.currentStateExitHandler != desiredStateExitHandler)
        {
            this.currentStateExitHandler!(this);
        }
    }


    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state ROOT
    ////////////////////////////////////////////////////////////////////////////////

    private void ROOT_enter()
    {
        // setup trigger/event handlers
        this.currentStateExitHandler = ptr_ROOT_exit;
    }

    // static delegate to avoid implicit conversion and garbage collection
    private static readonly Func ptr_ROOT_exit = (RocketSm sm) => sm.ROOT_exit();
    private void ROOT_exit()
    {
    }


    ////////////////////////////////////////////////////////////////////////////////
    // event handlers for state C1
    ////////////////////////////////////////////////////////////////////////////////

    private void C1_enter()
    {
        // setup trigger/event handlers
        this.currentStateExitHandler = ptr_C1_exit;
    }

    // static delegate to avoid implicit conversion and garbage collection
    private static readonly Func ptr_C1_exit = (RocketSm sm) => sm.C1_exit();
    private void C1_exit()
    {
        // adjust function pointers for this state's exit
        this.currentStateExitHandler = ptr_ROOT_exit;
    }

    // Thread safe.
    public static string StateIdToString(StateId id)
    {
        switch (id)
        {
            case StateId.ROOT: return "ROOT";
            case StateId.C1: return "C1";
            default: return "?";
        }
    }

    // Thread safe.
    public static string EventIdToString(EventId id)
    {
        switch (id)
        {
            case EventId.DO: return "DO";
            default: return "?";
        }
    }
}
