# StateSmith CLI Change Log
Note that this is a change log for the CLI tool, not the StateSmith library.

They have different version numbers.

# Releases
Test/interim releases are not documented here.

## wip
### Fixed (minor)
- Fix tool update check to consider alpha builds in comparison.
    - https://github.com/StateSmith/StateSmith/issues/351

### Change (minor)
- PlantUML - `create` templates modified to move initial transition below state definitions.
    - this will help new users in a few situations.

### Upgrade StateSmith library version to 
TODO copy in changes from StateSmith library.


---

## [0.10.0]
### Add
- Add prebuilt binaries for Windows, Linux, and Mac. No need to install dotnet anything unless you want .csx support.
  File sizes are around 145 MB, but may be reduced to around 90 MB in the future with IL trimming.
    - `win-x64`, `win-x86`, `win-arm64`
    - `osx-x64` (minimum macOS version is 10.12 Sierra)
    - `osx-arm64`
    - `linux-x64`, `linux-arm`, `linux-arm64`
    - `linux-musl-x64`, `linux-musl-arm64`
- Add ability to run diagrams even if `dotnet-script` is not installed.
- Add `run` CLI option `--no-csx` to skip running .csx scripts.
    - Useful if `dotnet-script` is not installed.
- Various CLI improvements.
    - Add top level `--help`.
    - Add `--version` to show version of CLI tool.
    - Parse enumeration values as case insensitive.
    - List allowed enumeration values.
- Add `run` CLI options for propagating and dumping exceptions to file.
    - https://github.com/StateSmith/StateSmith/issues/348

### Change (minor)
- Print `run` message `No .csx scripts found to run.` in default color.
    - no longer considered an error as we have diagram only projects.

### Fix (minor)
- CLI now sets process return code properly for CLI argument errors.
    - Also set if `run --help` or the like is used (cli lib side effect).
- Fix some printed error messages that ran across screen for Windows.
    - terminal lib (when in Windows) needed \r to return to start of line.
- Will stop running after first diagram-only (no-csx) failure instead of continuing.
    - This is consistent with .csx script running behavior and sets return code properly.
- Fix stack traces when diagram failed to parse.

### Upgrade StateSmith library version to 0.11.2-alpha
#### Fixed
- Fix error reporting for user injected code (via .csx) that has errors in it.
  - https://github.com/StateSmith/StateSmith/issues/283
- Fix error reporting when pre-parsing diagram for settings.
- Fix stack traces when pre-parsing diagram for settings.

#### Changed (minor)
- Modified PreDiagramSettingsReader to not run validations on diagram when reading settings.
  - https://github.com/StateSmith/StateSmith/issues/349
- Slight change to error reporting for better user experience.
- Reword exception detail message to be non-csx specific.
  - https://github.com/StateSmith/StateSmith/issues/348

#### Added
- Add help URL for user StateSmith grammar mistakes.
  - https://github.com/StateSmith/StateSmith/issues/174



---



## [0.9.3]
### Fix (minor)
- `run` command for "diagram-only" projects now prints the proper path for created files.
  - https://github.com/StateSmith/StateSmith/issues/345
  - Was not entirely fixed in 0.9.2 as intended (it included current directory).

---

## [0.9.2]
### Change (minor)
- `run` command for "diagram-only" projects now prints the proper path for created files.
    - https://github.com/StateSmith/StateSmith/issues/345

### Add
- Add ability for toml config to disable simulator file generation.

---

## [0.9.1]
### Change (minor)
- `create` command now asks if .csx file is desired. Defaults to "no" based on latest diagram-only work.
- `run` command now checks if diagrams specify `SmRunnerSettings.transpilerId` using toml if `--lang` is not specified.
- PlantUML is now the default diagram type for new users.
- PlantUML and drawio templates now include toml config that is updated based on target language.

### Upgrade StateSmith library version to 0.11.1
#### Add
- Add plantuml support for `note on link`
  - https://github.com/StateSmith/StateSmith/issues/343

---

## [0.9.0]
### Add
- `run` command now supports running diagrams with `--lang` option.
    - https://github.com/StateSmith/StateSmith/issues/285
    - Supports diagram based toml settings
        - https://github.com/StateSmith/StateSmith/issues/335
- `run` command detects broken drawio.svg files
    - https://github.com/StateSmith/StateSmith/issues/341
- `run` command supports `-v` verbose mode.
    - most grey text moved to verbose mode.
    - now also prints non-matching and intentionally ignored .csx/diagram files.

### Upgrade StateSmith library version to 0.11.0
#### Add
- Add diagram based toml config for `RenderConfig` and `SmRunner.Settings`
    - Useful for plantuml as well which previously never had diagram based render config support.
    - https://github.com/StateSmith/StateSmith/issues/335
- simulator - show implicit `do` edge trigger explicitly
    - https://github.com/StateSmith/StateSmith/issues/316
- Add default expansions for variables and functions.
    - https://github.com/StateSmith/StateSmith/issues/284
- Add convenience helpers for `SmTransformer`.

#### Fix
- simulator - prevent user diagram settings that could mess up generated simulation.
    - https://github.com/StateSmith/StateSmith/issues/337

---

## [0.8.2]
### Fixed
- Fix update check showing unlisted packages when it shouldn't
    - https://github.com/StateSmith/StateSmith/issues/269

---

## [0.8.1]
### Added
- Main menu option to check for updates
- Slight message improvements (print manifest success, etc)

---

## [0.8.0]
### Fixed
- fix generated vscode launch.json file
    - https://github.com/StateSmith/StateSmith/issues/263
- fix cursor missing after CTRL+C exiting menu/wizard
    - https://github.com/StateSmith/StateSmith/issues/256
- fix typo in `create-update-info.json`
    - `LastestStateSmithLibStableVersion` -> `LatestStateSmithLibStableVersion`
### Added
- Added tool settings for checking for tool updates
    - https://github.com/StateSmith/StateSmith/issues/249

---

## [0.7.2]
### Fixed
- Fix settings directory sometimes blank on WSL2
    - https://github.com/StateSmith/StateSmith/issues/255
### Changed
- Removed `--print-storage-paths` option from `create` verb
    - It now prints storage path always.

---

## [0.7.1]
### Added
- Support for `run` command.
- Support for `setup` command.

### Fixed
- Fixed detect if written/output files changed for skip detection
    - https://github.com/StateSmith/StateSmith/issues/246

---

## [0.6.6]
### Fixed
- Fixed user settings surviving tool upgrade.
    - On windows: `C:\Users\user\AppData\Roaming\StateSmith.Cli\`
    - On unix/mac: `~/.config/StateSmith.Cli/`
    - https://github.com/StateSmith/StateSmith/issues/244
### Added
- Updated language templates with common features needed.
- Initial support for `run` command.

--- 

## [0.6.4]
### Changed (minor)
- updated to use latest StateSmith library version 0.9.12

---

## [0.6.3]
### Added
- `create` - wizard defaults to use latest ss version bundled with CLI tool.
- `run` - print message saying not ready yet.
