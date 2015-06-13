#include <iostream>
#include <windows.h>
// for key pushing
BYTE scan_code(DWORD pKey)
{
    const DWORD result = MapVirtualKey(pKey, MAPVK_VK_TO_VSC);
    return static_cast<BYTE>(result);
}
void press_key(DWORD pKey)
{
    keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), 0, 0);
}
void release_key(DWORD pKey)
{
    keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), KEYEVENTF_KEYUP, 0);
}
// for testing
#define PRESS(x) press_key(x); std::cout << "Press: " #x << std::endl
#define RELEASE(x) release_key(x); std::cout << "Release: " #x << std::endl
// test
void main(void)
{
    for (;;)
    {
		Sleep(6000); // wait for 6 seconds

        PRESS(VK_LEFT);
        Sleep(10); // hold it for 1/100'th of a second
        RELEASE(VK_LEFT);
        Sleep(1000); // wait for a second
        PRESS(VK_RIGHT);
        Sleep(10); // hold it for 1/100'th of a second
        RELEASE(VK_RIGHT);
        Sleep(1000); // wait for a second
    }
}