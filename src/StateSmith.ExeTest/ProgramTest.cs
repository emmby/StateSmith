using CommandLine;
using Spectre.Console.Testing;
using System;
using System.Linq;
using Xunit;
using FluentAssertions;

namespace StateSmith.Exe.Tests
{
    public class ProgramTest
    {
        [Fact]
        public void ParseCommands_ValidArgs_ReturnsZero()
        {
            // Arrange
            var args = new[] { "--lang", "C99" };
            var console = new TestConsole();
            var program = new Program();

            // Act
            var result = Program.ParseCommands(args, console, program);

            // Assert
            result.Should().Be(0);
            program._options.Lang.Should().Be("C99");
        }

        [Fact]
        public void ParseCommands_InvalidArgs_ReturnsOne()
        {
            // Arrange
            var args = new[] { "--invalidOption" };
            var console = new TestConsole();
            var program = new Program();

            // Act
            var result = Program.ParseCommands(args, console, program);

            // Assert
            result.Should().Be(1);
        }

        [Fact]
        public void Run_ExecutesWithoutException()
        {
            // Arrange
            var console = new TestConsole();
            var program = new Program();
            program._options.Files = new[] { "file1", "file2" };

            // Act
            Action act = () => program.Run();

            // Assert
            act.Should().NotThrow();
        }


        [Fact]
        public void Run_NoArgs()
        {
            // Arrange
            var console = new TestConsole();
            var program = new Program();
            program._options.Files = new string[] { }; // Correcting the initialization of Files to use string[]

            // Act
            Action act = () => program.Run();

            // Assert
            act.Should().NotThrow();
            console.Output.Should().Contain("StateSmith - a state machine diagram tool.");
        }

        [Fact]
        public void PrintUsage_DisplaysHelpText()
        {
            // Arrange
            var args = new[] { "--help" };
            var console = new TestConsole();
            var program = new Program();
            var parserResult = new Parser().ParseArguments<ProgramOptions>(args);

            // Act
            Program.PrintUsage(parserResult, console);

            // Assert
            console.Output.Should().Contain("StateSmith - a state machine diagram tool.");
        }
    }
}