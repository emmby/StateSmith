using StateSmith.Cli.Utils;
using StateSmith.Common;
using StateSmith.Output;
using System.IO;
using System.Text.RegularExpressions;
using System.Web;

namespace StateSmith.Cli.Create;

public class Generator
{
    private Settings settings;
    private IFileWriter fileWriter = new FileWriter();

    public Generator(Settings settings)
    {
        this.settings = settings;
    }

    public void SetFileWriter(IFileWriter fileWriter)
    {
        this.fileWriter = fileWriter;
    }

    public void GenerateFiles()
    {
        if (settings.UseCsxWorkflow)
        {
            GenerateCsx();
        }
        GenerateDiagramFile();
    }

    public void GenerateCsx()
    {
        var templateStr = TemplateLoader.LoadCsxOrDefault(settings.GetTemplateId());

        string diagramFilePathRelative = GetDiagramPathRelativeToCsx();

        var r = new CsxTemplateRenderer(settings.TargetLanguageId, stateSmithVersion: settings.StateSmithVersion, diagramPath: diagramFilePathRelative, smName: settings.smName, template: templateStr);
        var result = r.Render();
        fileWriter.Write(settings.scriptFileName, result);
    }

    private string GetDiagramPathRelativeToCsx()
    {
        var currentDir = Directory.GetCurrentDirectory();
        var scriptAbsolutePath = PathUtils.EnsurePathAbsolute(settings.scriptFileName, currentDir);
        var diagramAbsolutePath = PathUtils.EnsurePathAbsolute(settings.diagramFileName, currentDir);
        string diagramFilePathRelative = Path.GetRelativePath(Path.GetDirectoryName(scriptAbsolutePath).ThrowIfNull(), diagramAbsolutePath);
        return diagramFilePathRelative;
    }

    internal static string GetTomlConfig(TargetLanguageId targetLanguageId)
    {
        var tomlConfigTemplate = TemplateLoader.LoadTomlConfig();
        var filterEngine = new TemplateFilterEngine();
        var result = filterEngine.ProcessAllFilters(tomlConfigTemplate, filterTag: targetLanguageId.ToString());
        
        return result;
    }

    public void GenerateDiagramFile()
    {
        string diagramTemplateStr = GenerateDiagramFileText();
        fileWriter.Write(settings.diagramFileName, diagramTemplateStr);
    }

    public string GenerateDiagramFileText()
    {
        var diagramTemplateStr = TemplateLoader.LoadDiagram(settings.GetTemplateId(), isDrawIoSelected: settings.IsDrawIoSelected());
        diagramTemplateStr = diagramTemplateStr.Replace("{{smName}}", settings.smName);
        diagramTemplateStr = SupportDefaultTomlConfig(diagramTemplateStr);

        // allow plantuml diagrams to be customized by selected language
        if (settings.IsPlantUmlSelected())
        {
            var filterEngine = new TemplateFilterEngine();
            diagramTemplateStr = filterEngine.ProcessAllFilters(diagramTemplateStr, filterTag: settings.TargetLanguageId.ToString());
        }

        if (settings.IsDrawIoSvgSelected())
        {
            diagramTemplateStr = WrapDrawioXmlForSvg(diagramTemplateStr);
        }

        return diagramTemplateStr;
    }

    private string SupportDefaultTomlConfig(string diagramTemplateStr)
    {
        var tomlConfig = GetTomlConfig(settings.TargetLanguageId);

        if (settings.UseCsxWorkflow == false)
        {
            // simpler workflow (no csx) so the toml should specify the transpilerId.
            // modify toml so transpilerId line is uncommented.
            tomlConfig = tomlConfig.Replace("# transpilerId = ", "transpilerId = ");
        }

        if (settings.IsDrawIoSelected())
        {
            tomlConfig = HttpUtility.HtmlEncode(tomlConfig);
            tomlConfig = StringUtils.ReplaceNewLineChars(tomlConfig, "&#10;");
        }

        diagramTemplateStr = diagramTemplateStr.Replace("{{configToml}}", tomlConfig);
        return diagramTemplateStr;
    }

    public static string WrapDrawioXmlForSvg(string drawioXml)
    {
        string wrapper = TemplateLoader.LoadFileResource("_global-svg", "svg-wrapper.drawio.svg");
        drawioXml = HttpUtility.HtmlEncode(drawioXml);
        wrapper = Regex.Replace(wrapper, "content\\s*=\\s*\"[^\"]+\"", $"content=\"{drawioXml}\"");
        return wrapper;
    }
}
