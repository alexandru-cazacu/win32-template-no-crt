int _fltused;

#ifdef _M_IX86 // following functions are needed only for 32-bit architecture

__declspec(naked) void _ftol2()
{
    __asm
    {
        fistp qword ptr [esp-8]
            mov   edx,[esp-4]
            mov   eax,[esp-8]
            ret
    }
}

__declspec(naked) void _ftol2_sse()
{
    __asm
    {
        fistp dword ptr [esp-4]
            mov   eax,[esp-4]
            ret
    }
}

#endif
