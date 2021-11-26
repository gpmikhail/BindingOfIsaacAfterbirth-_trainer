// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"


void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

DWORD WINAPI HackThread(HMODULE hModule)
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    ShowConsoleCursor(false);
    for (int i = 0; i < 41; i++) std::cout << " ";
    std::cout << "Welcome to BindingOfIsaacReprntance Internal V1.00\n\n";
    for (int i = 0; i < 56; i++) std::cout << " ";
    std::cout << "Hotkeys:\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Freeze Health: \t\t[NUMPAD_1]\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Freeze spHearts: \t\t[NUMPAD_2]\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Freeze Coins: \t\t[NUMPAD_3]\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Infinite Bombs: \t\t[NUMPAD_4]\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Infinite Keys: \t\t[NUMPAD_5]\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Fast Charge: \t\t[NUMPAD_7]\n";
    for (int i = 0; i < 43; i++) std::cout << " ";
    std::cout << "Super Charge: \t\t[NUMPAD_8]\n\n\n\n";



    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"isaac-ng.exe");
    moduleBase = (uintptr_t)GetModuleHandle(NULL);
    //std::cout << std::hex <<  moduleBase << std::endl;

    bool bHealth = false, bSpHealth = false, bInfCoins = false, bInfBombs = false, bInfKeys = false, bFastCharge = false, bSuperCharge = false;

    BYTE* origHealth = new BYTE[6];
    BYTE* origSpHealth = new BYTE[2];
    BYTE* origCoins = new BYTE[6];
    BYTE* origKeys = new BYTE[6];
    BYTE* origBombs = new BYTE[6];
    BYTE* origFastCharge = new BYTE[8];
    BYTE* origSuperCharge = new BYTE[7];




    while (true)
    {
        std::cout << ((bHealth) ? "  Hlth [ON]" : "  Hlth [OFF]") << ((bSpHealth) ? "\tsHlth [ON]" : "\tsHlth [OFF]") << ((bInfCoins) ? "\tCoin [ON]  " : "\tCoin [OFF]  ") << ((bInfBombs) ? "\tBomb [ON]  " : "\tBomb [OFF]  ") << ((bInfKeys) ? "\tKey [ON]  " : "\tKey [OFF]  ") << ((bFastCharge) ? "\tFChr [ON]  " : "\tFChr [OFF]  ") << ((bSuperCharge) ? "\tSChr [ON]  " : "\tSChr [OFF]  ") << "\r" << std::flush;
        
        if (GetAsyncKeyState(VK_END) & 1)
        {
            break;
        }

        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {
            bHealth = !bHealth;
            if (bHealth)
            {
                memcpy(origHealth, (BYTE*)(moduleBase + 0x2F2341), 6);
                mem::Nop((BYTE*)(moduleBase + 0x2F2341), 6);
            }
            else
            {
                mem::Patch((BYTE*)(moduleBase + 0x2F2341), origHealth, 6);
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            bSpHealth = !bSpHealth;

            if (bSpHealth)
            {
                memcpy(origSpHealth, (BYTE*)(moduleBase + 0x30C87D), 2);
                mem::Nop((BYTE*)(moduleBase + 0x30C87D), 2);
            }
            else
            {
                mem::Patch((BYTE*)(moduleBase + 0x30C87D), origSpHealth, 2);
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            bInfCoins = !bInfCoins;

            if (bInfCoins)
            {
                memcpy(origCoins, (BYTE*)(moduleBase + 0x2F2B54), 6);
                mem::Nop((BYTE*)(moduleBase + 0x2F2B54), 6);
            }
            else
            {
                mem::Patch((BYTE*)(moduleBase + 0x2F2B54), origCoins, 6);
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            bInfBombs = !bInfBombs;

            if (bInfBombs)
            {
                memcpy(origBombs, (BYTE*)(moduleBase + 0x2F2C07), 6);
                mem::Nop((BYTE*)(moduleBase + 0x2F2C07), 6);
            }
            else
            {
                mem::Patch((BYTE*)(moduleBase + 0x2F2C07), origBombs, 6);
            }

        }
        
        if (GetAsyncKeyState(VK_NUMPAD5) & 1)
               {
                   bInfKeys = !bInfKeys;
                        if (bInfKeys)
                        {
                            memcpy(origKeys, (BYTE*)(moduleBase + 0x2F3489), 6);
                            mem::Nop((BYTE*)(moduleBase + 0x2F3489), 6);
                        }
                        else
                        {
                            mem::Patch((BYTE*)(moduleBase + 0x2F3489), origKeys, 6);
                        }
                }

        if (GetAsyncKeyState(VK_NUMPAD7) & 1)
        {
            bFastCharge = !bFastCharge;
            if (bFastCharge)
            {
                memcpy(origFastCharge, (BYTE*)(moduleBase + 0x4F9D0B), 8);
                mem::Nop((BYTE*)(moduleBase + 0x4F9D0B), 8);
            }
            else
            {
                mem::Patch((BYTE*)(moduleBase + 0x4F9D0B), origFastCharge, 8);
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD8) & 1)
        {
            bSuperCharge = !bSuperCharge;
            if (bSuperCharge)
            {
                memcpy(origSuperCharge, (BYTE*)(moduleBase + 0x4FA81D), 7);
                mem::Nop((BYTE*)(moduleBase + 0x4FA81D), 7);
            }
            else
            {
                mem::Patch((BYTE*)(moduleBase + 0x4FA81D), origSuperCharge, 7);
            }
        }

            

        Sleep(5);
    }

    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    delete[] origHealth;
    delete[] origSpHealth;
    delete[] origCoins;
    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

