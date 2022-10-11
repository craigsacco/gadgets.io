#!powershell

$ErrorActionPreference = "Stop"

function Reformat-Code {
	param ( $FullName )
    echo "${FullName}"
	& ${Env:VSINSTALLDIR}\Vc\Tools\Llvm\bin\clang-format.exe -i "${FullName}"
}

Get-ChildItem -Include *.cpp,*.h -Recurse | ForEach { Reformat-Code $_.FullName }

