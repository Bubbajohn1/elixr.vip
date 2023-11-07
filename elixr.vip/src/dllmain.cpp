// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <thread>
#include <iostream>
#include "debugging/console.hpp"
#include "core/il2.hpp"

unsigned long main_thread( void* ) {
  il2::init();
    
    AllocConsole();

    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONIN$", "r", stdin);
    SetConsoleTitleA("Internal Console");

  //std::cout << "game_assembly: " << std::hex << il2::game_assembly << std::endl;
  //std::cout << "unity_player: " << std::hex << il2::unity_player << std::endl;

  //while (!GetAsyncKeyState(VK_END)) {
  //    player_input plr_input;
  //    vec2 view_angles = plr_input.get_view_angles();
  //    std::cout << "view_angles.x: " << view_angles.x << std::endl;
   //   std::cout << "view_angles.y: " << view_angles.y << std::endl;
  //
   //   Sleep(100);
  //}

  return 0;
}

bool APIENTRY DllMain( void* hModule, unsigned long ul_reason_for_call, void* lpReserved ) {
  if (ul_reason_for_call != 1)
     return false;

  const auto handle = CreateThread( nullptr, 0, &main_thread, nullptr, 0, nullptr );

  if( handle )
     CloseHandle( handle );  

  return true;
}

