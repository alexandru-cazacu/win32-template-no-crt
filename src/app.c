#include "win32_crt_memory.c"
#include "win32_crt_float.c"
#include "win32_crt_math.c"
#include "win32.c"

typedef enum { false, true } bool;

#define global_variable static

global_variable g_running = true;

LRESULT CALLBACK Win32WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
	HDC hdc;
    
	switch(uMsg) {
		case WM_CREATE: {
			return(0);
		} break;
		
		case WM_PAINT: {
			hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			return(0);
		} break;
        
        case WM_CLOSE: {
            if (MessageBoxA(hwnd, "Really quit?", "Win32App", MB_OKCANCEL | MB_ICONQUESTION) == IDOK) {
                DestroyWindow(hwnd);
            }
            return 0;
        }
        
		case WM_DESTROY: {
			PostQuitMessage(0);
			return(0);
		} break;
        
		default: break;
	}
    
    return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    WNDCLASSA winclass = {0};
    winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = Win32WndProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = "AppWin32";
    
    RegisterClassA(&winclass);
    
    HWND hwnd = CreateWindowA("AppWin32",          // Window class
                              "AppWin32",          // Window text
                              WS_OVERLAPPEDWINDOW, // Window style
                              CW_USEDEFAULT, CW_USEDEFAULT, // Size
                              CW_USEDEFAULT, CW_USEDEFAULT, // Position
                              NULL,       // Parent window    
                              NULL,       // Menu
                              hInstance,  // Instance handle
                              NULL);      // Additional application data
    
    
    if (hwnd == NULL) {
        MessageBoxA(hwnd, "Failed to create Window.", "Win32App", MB_OK | MB_ICONERROR);
        return 0;
    }
    
    ShowWindow(hwnd, nCmdShow);
    
    MSG msg = {0};
    while(g_running) {
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if(msg.message == WM_QUIT) {
                g_running = false;
            }
            
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
        Sleep(1);
	}
    
    return 0;
}

void CALLBACK WinMainCRTStartup()
{
    int result = WinMain(GetModuleHandleA(0), 0, 0, SW_SHOW);
    ExitProcess(result);
}