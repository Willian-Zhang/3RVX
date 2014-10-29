﻿#include "3RVX.h"
#include "Controllers\Volume\IVolume.h"
#include "Controllers\Volume\CoreAudio.h"
#include "VolumeOSD.h"
#include <Wtsapi32.h>
#include "Logger.h"
#include "Settings.h"

int APIENTRY
wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
LPTSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    using namespace Gdiplus;
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

#ifdef _DEBUG
    Logger::OpenConsole();
#endif

    QCLOG(L"  _____ ______     ____  _______ ");
    QCLOG(L" |___ /|  _ \\ \\   / /\\ \\/ /___ / ");
    QCLOG(L"   |_ \\| |_) \\ \\ / /  \\  /  |_ \\ ");
    QCLOG(L"  ___) |  _ < \\ V /   /  \\ ___) |");
    QCLOG(L" |____/|_| \\_\\ \\_/   /_/\\_\\____/ ");
    QCLOG(L"");

    QCLOG(L"Starting up...");

    mainWnd = CreateMainWnd(hInstance);
    if (mainWnd == NULL) {
        CLOG(L"Could not create main window");
        return EXIT_FAILURE;
    }

    HRESULT hr = CoInitializeEx(NULL,
        COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (hr != S_OK) {
        CLOG(L"Failed to initialize the COM library.");
        return EXIT_FAILURE;
    }

    /* Tell the program to initialize */
    PostMessage(mainWnd, WM_3RVX_CONTROL, MSG_LOAD, NULL);

    /* Start the event loop */
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    GdiplusShutdown(gdiplusToken);
    return (int)msg.wParam;
}

void Init() {
    CLOG(L"Initializing...");
    ca = new CoreAudio(mainWnd);
    ca->Init();
    float v = ca->Volume();

//    Meter *m = new HorizontalEndcap(L"meter.png", 71, 29, 28);
//    mW = new MeterWnd(hInst, L"testtest", L"what what");
//    mW->AddMeter(m);
//    std::wstring bgbmp(L"bg.png");
//    mW->SetBackgroundImage(Gdiplus::Bitmap::FromFile(bgbmp.c_str(), true));
//    mW->MeterLevels(v);
//    mW->Update();
//    mW->Show();

    Settings s(L"Settings.xml");

    vOsd = new VolumeOSD(hInst);
    vOsd->LoadSkin(s.SkinName());
    vOsd->MeterLevels(v);

    WTSRegisterSessionNotification(mainWnd, NOTIFY_FOR_THIS_SESSION);

    HotkeyManager *hkManager = HotkeyManager::Instance();
    hkManager->Register(mainWnd, HKM_MOD_WIN + VK_BACK);
    hkManager->Register(mainWnd, HKM_MOD_WIN + HKM_MOUSE_WHUP);

    CLOG(L"%d", HKM_MOD_WIN + VK_UP);
}

HWND CreateMainWnd(HINSTANCE hInstance) {
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = NULL;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = NULL;
    wcex.cbWndExtra = NULL;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"3RVX";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex)) {
        return NULL;
    }

    HWND hWnd = CreateWindowEx(
        NULL,
        L"3RVX", L"3RVX",
        NULL, NULL, NULL, //your boat, gently down the stream
        NULL, NULL, HWND_MESSAGE, NULL, hInstance, NULL);

    return hWnd;
}

LRESULT CALLBACK WndProc(
    HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    switch (message) {
    case MSG_VOLCHNG: {
        float v = ca->Volume();
        QCLOG(L"Volume level: %.0f", v * 100.0f);
        vOsd->MeterLevels(v);
        break;
    }

    case MSG_DEVCHNG:
        CLOG(L"Device change detected.");
        ca->ReattachDefaultDevice();
        break;

    case WM_HOTKEY:
        CLOG(L"Hotkey: %d", (int) wParam);
        break;

    case WM_WTSSESSION_CHANGE:
        CLOG(L"Detected session change");
        break;
    }

    if (message == WM_3RVX_CONTROL) {
        switch (wParam) {
        case MSG_LOAD:
            Init();
            break;

        case 101:
            printf("%x\n", lParam);
            break;
        }
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}