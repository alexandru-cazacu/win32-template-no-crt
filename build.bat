@echo off

set exe_name=appWin32
set build_options= /DBUILD_WIN32=1
set compile_flags= /nologo /Oi /Gm- /GR- /EHa- /Zi /FC /GS- /Gs9999999  /I ../src/
set link_flags= /opt:ref /incremental:no /NODEFAULTLIB /subsystem:windows /STACK:0x100000,0x100000 kernel32.lib user32.lib gdi32.lib

if not exist build mkdir build

pushd build
    cl %build_options% %compile_flags% ../src/app.c /link %link_flags% /out:%exe_name%.exe
    copy ..\data\* . >NUL
popd

:: ╔════════════════╗
:: ║ Compiler Flags ║
:: ╚════════════════╝

:: Oi            Generates intrinsic functions.
:: O2            Creates fast code.
:: Gm-           Disables minimal recompilation.
:: GR-           Disables run-time type information (RTTI).
:: EHa-          Disables exception handling.
:: Zi            Generates complete debugging information.
:: FC            Display full path of source code files passed to cl.exe in diagnostic text.
:: Fd:<file>     Renames program database file.
:: Fe:<file.exe> Renames the executable file.
:: Fo:<file>     Creates an object file.
:: Fm:<file>     Creates a mapfile.
:: D <name>      Defines constants and macros.
:: I <dir>       Searches a directory for include files.

:: ╔══════════════╗
:: ║ Linker Flags ║
:: ╚══════════════╝