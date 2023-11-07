#include "./console.hpp"

void create_console() {
    HWND console_hwnd = GetConsoleWindow();

    if(!console_hwnd) {
        AllocConsole();

        freopen_s(&f, "CONOUT$", "w", stdout);
        freopen_s(&f, "CONIN$", "r", stdin);
        SetConsoleTitleA("Internal Console");
    } else {
        ShowWindow(GetConsoleWindow(), SW_SHOW);
    }
}

void close_console() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    clear_console();
}

void clear_console() {
    system("cls");
}