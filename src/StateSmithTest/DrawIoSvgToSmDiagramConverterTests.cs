﻿using System.IO;
using Xunit;
using StateSmith.Input.DrawIo;
using System.Linq;
using FluentAssertions;
using StateSmith.Runner;
using StateSmith.Compiling;
using StateSmith.compiler;

namespace StateSmithTest.DrawIo;

public class DrawIoSvgToSmDiagramConverterTests
{
    [Fact]
    public void Test()
    {
        string filePath = ExamplesTestHelpers.TestInputDirectoryPath + "drawio/Design1Sm.drawio.svg";
        DrawIoToSmDiagramConverter converter = new();
        converter.ProcessSvg(File.OpenText(filePath));

        var smDiagramRoot = converter.Roots.Single();
        smDiagramRoot.label.Should().Be("$STATEMACHINE: Design1Sm_svg");
        smDiagramRoot.children.Count.Should().Be(4);
        int i = 0;
        smDiagramRoot.children[i].label.Should().Be("ON_GROUP");
        smDiagramRoot.children[i].parent.Should().Be(smDiagramRoot);
        smDiagramRoot.children[i].children.Count.Should().Be(3);

        // could do more tests here for all nodes and edges

        CompilerRunner runner = new();
        runner.CompileNodesToVertices(converter.Roots, converter.Edges);
        runner.FindSingleStateMachine();
        runner.sm.Name.Should().Be("Design1Sm_svg");
        ValidateSm(runner);
    }

    [Fact]
    public void CompileDrawIoSvgFileNodesToVertices()
    {
        string filePath = ExamplesTestHelpers.TestInputDirectoryPath + "drawio/Design1Sm.drawio.svg";

        CompilerRunner runner = new();
        runner.CompileDrawIoFileNodesToVertices(filePath);
        runner.FindSingleStateMachine();

        runner.sm.Name.Should().Be("Design1Sm_svg");
        ValidateSm(runner);
    }

    [Fact]
    public void CompileDrawIoFileNodesToVertices_Compressed()
    {
        string filePath = ExamplesTestHelpers.TestInputDirectoryPath + "drawio/Design1Sm_compressed.drawio";
        File.ReadAllText(filePath).Should().NotContain("<mxGraphModel", because: "this file needs to be compressed");
        // Note that vscode extension tends to write file uncompressed, but draw.io windows app tends to write it compressed.

        CompilerRunner runner = new();
        runner.CompileDrawIoFileNodesToVertices(filePath);
        runner.FindSingleStateMachine();

        runner.sm.Name.Should().Be("Design1Sm_compressed");
        ValidateSm(runner);
    }

    [Fact]
    public void CompileDrawIoFileNodesToVertices_UncompressedFile()
    {
        string filePath = ExamplesTestHelpers.TestInputDirectoryPath + "drawio/Design1Sm_regular.drawio";
        File.ReadAllText(filePath).Should().Contain("<mxGraphModel", because: "this should not be compressed");
        // Note that vscode extension tends to write file uncompressed, but draw.io windows app tends to write it compressed.

        CompilerRunner runner = new();
        runner.CompileDrawIoFileNodesToVertices(filePath);
        runner.FindSingleStateMachine();

        runner.sm.Name.Should().Be("Design1Sm_regular");
        ValidateSm(runner);
    }

    [Fact]
    public void CompileDrawIoFileNodesToVertices_UncompressedDioFile()
    {
        string filePath = ExamplesTestHelpers.TestInputDirectoryPath + "drawio/Design1Sm_regular_dio.dio";
        File.ReadAllText(filePath).Should().Contain("<mxGraphModel", because: "this should not be compressed");
        // Note that vscode extension tends to write file uncompressed, but draw.io windows app tends to write it compressed.

        CompilerRunner runner = new();
        runner.CompileDrawIoFileNodesToVertices(filePath);
        runner.FindSingleStateMachine();

        runner.sm.Name.Should().Be("Design1Sm_regular_dio");
        ValidateSm(runner);
    }

    [Fact]
    public void CompileDrawIoFileNodesToVertices_WithImage()
    {
        string filePath = ExamplesTestHelpers.TestInputDirectoryPath + "drawio/Design1Sm_with_image.drawio.svg";

        CompilerRunner runner = new();
        runner.CompileDrawIoFileNodesToVertices(filePath);
        runner.FindSingleStateMachine();
        runner.sm.Name.Should().Be("Design1Sm_with_image");

        runner.RemoveNotesVertices();
        ValidateSm(runner);
    }

    private static void ValidateSm(CompilerRunner runner)
    {
        var sm = runner.sm;

        State GetState(string stateName)
        {
            return (State)sm.Descendant(stateName);
        }

        sm.ShouldHaveChildrenAndUmlBehaviors("ROOT.InitialState, OFF, ON_GROUP, BOOM", "");

        GetState("OFF").ShouldHaveChildrenAndUmlBehaviors("", $$"""
            enter / { light_off(); }
            INCREASE TransitionTo(ON1)
            """
        );

        GetState("ON_GROUP").ShouldHaveChildrenAndUmlBehaviors("ON1, ON2, ON3", $$"""
            OFF TransitionTo(OFF)
            """
        );

        GetState("ON1").ShouldHaveChildrenAndUmlBehaviors("", $$"""
            enter / { light_on1(); }
            INCREASE TransitionTo(ON2)
            DIM TransitionTo(OFF)
            """
        );

        GetState("ON2").ShouldHaveChildrenAndUmlBehaviors("", $$"""
            enter / { light_on2(); }
            INCREASE TransitionTo(ON3)
            DIM TransitionTo(ON1)
            """
        );

        GetState("ON3").ShouldHaveChildrenAndUmlBehaviors("", $$"""
            1. INCREASE / { count++; }
            2. INCREASE [count >= 3] TransitionTo(BOOM)
            enter / { count = 0;\nlight_on3(); }
            DIM TransitionTo(ON2)
            """
        );

        GetState("BOOM").ShouldHaveChildrenAndUmlBehaviors("", $$"""
            enter / { light_boom(); }
            """
        );
    }
}
