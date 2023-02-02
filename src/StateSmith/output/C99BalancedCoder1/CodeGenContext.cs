﻿using StateSmith.SmGraph;
using StateSmith.Input.Expansions;
using StateSmith.Output.UserConfig;
using System.Text;

# nullable enable

namespace StateSmith.Output.C99BalancedCoder1
{
    public class CodeGenContext
    {
        public CodeStyleSettings style;
        public CNameMangler mangler;
        public StringBuilder hFileSb = new();
        public StringBuilder cFileSb = new();
        public StateMachine sm;
        public Expander expander;
        public IRenderConfigC renderConfig;
        public PseudoStateHandlerBuilder pseudoStateHandlerBuilder = new();

        internal CodeGenContext(StateMachine sm)
        {
            this.sm = sm;
            mangler = new(sm);
            renderConfig = new DummyRenderConfigC();
            expander = new();
            style = new();
        }

        public CodeGenContext(StateMachine sm, IRenderConfigC renderConfig, Expander expander, CNameMangler mangler, CodeStyleSettings style)
        {
            this.sm = sm;
            this.renderConfig = renderConfig;
            this.expander = expander;
            this.mangler = mangler;
            this.style = style;
        }

        public void AddExpansions(UserExpansionScriptBase userObject)
        {
            ExpanderFileReflection expanderFileReflection = new ExpanderFileReflection(expander);
            expanderFileReflection.AddAllExpansions(userObject);
        }
    }
}
