#include "Includes.h"
#include "WndProc.h"

MemoryManager *m = new MemoryManager();

ATOM RegMyWindowClass(HINSTANCE hInst, LPCTSTR lpzClassName) {
	WNDCLASS wcWindowClass = { 0 };
	wcWindowClass.lpfnWndProc = (WNDPROC)WndProc;
	wcWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	wcWindowClass.hInstance = hInst;
	wcWindowClass.lpszClassName = lpzClassName;
	wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	return RegisterClass(&wcWindowClass);
}

void DoHacks() {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pMisc->Bhop, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pVisuals->Chams, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pVisuals->noFlash, 0, 0, 0);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DoHacks, 0, 0, 0);

	const wchar_t* title = L"'AAAHBASE EXTERNAL'";
	LPCTSTR lpzClass = (LPCTSTR)title;
	if (!RegMyWindowClass(hInstance, lpzClass))
		return 1;
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 2 - 75;
	HWND hWnd = CreateWindow(lpzClass, (LPCTSTR)title, WS_POPUP, x, y, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	if (!hWnd) 
		return 2;

	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL) {
		UnregisterClass(lpzClass, hInstance);
	}

	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0) {
		pD3D->Release();
		UnregisterClass(lpzClass, hInstance);
		return 0;
	}

	ImGui_ImplDX9_Init(hWnd, g_pd3dDevice);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (msg.message != WM_QUIT && !GetAsyncKeyState(VK_DELETE) && g_Variables::csgowindow) { // delete = panic button
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		DoGUI(g_pd3dDevice);
	}

	ImGui_ImplDX9_Shutdown();

	if (g_pd3dDevice) 
		g_pd3dDevice->Release();
	if (pD3D) 
		pD3D->Release();
	UnregisterClass((LPCWSTR)title, hInstance);
	return 0;
}