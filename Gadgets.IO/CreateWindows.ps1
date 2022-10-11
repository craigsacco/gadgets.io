#!powershell

$ErrorActionPreference = "Stop"

& ${Env:ProgramFiles}\Cmake\bin\cmake.exe -S . -B build_windows
