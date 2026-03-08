#include <iostream>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "Engine.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    Engine engine;
    engine.intialize();
    engine.run();
    engine.shutdown();

    return 0;
}