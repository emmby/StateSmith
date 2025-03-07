# Autogenerated with StateSmith.
# Algorithm: Balanced2. See https:#github.com/StateSmith/StateSmith/wiki/Algorithms

import enum
# Generated state machine
class RocketSm():
    class EventId(enum.Enum):
        DO = 0
    
    
    class StateId(enum.Enum):
        ROOT = 0
        GROUP = 1
        G1 = 2
        G2 = 3
    
    # State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
    def __init__(self, *args, **kwargs):
        # Used internally by state machine. Feel free to inspect, but don't modify.
        self.stateId = None
    
    # Starts the state machine. Must be called before dispatching events. Not thread safe.
    def start(self):
        self._ROOT_enter()
        # ROOT behavior
        # uml: TransitionTo(ROOT.<InitialState>)
        if True:
            # Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            # Step 2: Transition action: ``.
            
            # Step 3: Enter/move towards transition target `ROOT.<InitialState>`.
            # ROOT.<InitialState> is a pseudo state and cannot have an `enter` trigger.
            
            # ROOT.<InitialState> behavior
            # uml: TransitionTo(group)
            if True:
                # Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
                
                # Step 2: Transition action: ``.
                
                # Step 3: Enter/move towards transition target `group`.
                self._GROUP_enter()
                
                # group.<InitialState> behavior
                # uml: TransitionTo(g1)
                if True:
                    # Step 1: Exit states until we reach `group` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
                    
                    # Step 2: Transition action: ``.
                    
                    # Step 3: Enter/move towards transition target `g1`.
                    self._G1_enter()
                    
                    # Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
                    return
                # end of behavior for group.<InitialState>
            # end of behavior for ROOT.<InitialState>
        # end of behavior for ROOT
    
    
    # Dispatches an event to the state machine. Not thread safe.
    # Note! This function assumes that the `eventId` parameter is valid.
    def dispatchEvent(self, eventId):
        
        match self.stateId:
            # STATE: RocketSm
            case RocketSm.StateId.ROOT:
                pass
            
            # STATE: group
            case RocketSm.StateId.GROUP:
                pass
            
            # STATE: g1
            case RocketSm.StateId.G1:
                self._G1_do() 
            
            # STATE: g2
            case RocketSm.StateId.G2:
                self._G2_do() 
        
    
    
    # This function is used when StateSmith doesn't know what the active leaf state is at
    # compile time due to sub states or when multiple states need to be exited.
    def _exitUpToStateHandler(self, desiredState):
        while (self.stateId != desiredState):

            match self.stateId:
                case RocketSm.StateId.GROUP:
                    self._GROUP_exit()
                
                case RocketSm.StateId.G1:
                    self._G1_exit()
                
                case RocketSm.StateId.G2:
                    self._G2_exit()
                
                case _:
                    return  # Just to be safe. Prevents infinite loop if state ID memory is somehow corrupted.
        
    
    
    
    ########################################
    # event handlers for state ROOT
    ########################################
    
    def _ROOT_enter(self):
        self.stateId = RocketSm.StateId.ROOT
    
    
    
    ########################################
    # event handlers for state GROUP
    ########################################
    
    def _GROUP_enter(self):
        self.stateId = RocketSm.StateId.GROUP
    
    
    def _GROUP_exit(self):
        self.stateId = RocketSm.StateId.ROOT
    
    
    
    ########################################
    # event handlers for state G1
    ########################################
    
    def _G1_enter(self):
        self.stateId = RocketSm.StateId.G1
    
    
    def _G1_exit(self):
        self.stateId = RocketSm.StateId.GROUP
    
    
    def _G1_do(self):
        # g1 behavior
        # uml: do TransitionTo(g2)
        if True:
            # Step 1: Exit states until we reach `group` state (Least Common Ancestor for transition).
            self._G1_exit()
            
            # Step 2: Transition action: ``.
            
            # Step 3: Enter/move towards transition target `g2`.
            self._G2_enter()
            
            # Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            return
        # end of behavior for g1
        
        # No ancestor handles this event.
    
    
    
    ########################################
    # event handlers for state G2
    ########################################
    
    def _G2_enter(self):
        self.stateId = RocketSm.StateId.G2
    
    
    def _G2_exit(self):
        self.stateId = RocketSm.StateId.GROUP
    
    
    def _G2_do(self):
        # g2 behavior
        # uml: do [x > 50] TransitionTo(g1)
        if x > 50:
            # Step 1: Exit states until we reach `group` state (Least Common Ancestor for transition).
            self._G2_exit()
            
            # Step 2: Transition action: ``.
            
            # Step 3: Enter/move towards transition target `g1`.
            self._G1_enter()
            
            # Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            return
        # end of behavior for g2
        
        # No ancestor handles this event.
    
    
    # Thread safe.
    @staticmethod
    def stateIdToString(id):
        match id:
            case RocketSm.StateId.ROOT: return "ROOT"
            case RocketSm.StateId.GROUP: return "GROUP"
            case RocketSm.StateId.G1: return "G1"
            case RocketSm.StateId.G2: return "G2"
            case _: return "?"
    
    
    # Thread safe.
    @staticmethod
    def eventIdToString(id):
        match id:
            case RocketSm.EventId.DO: return "DO"
            case _: return "?"
    
