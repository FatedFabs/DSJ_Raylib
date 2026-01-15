#include "GameEngine.h"
#include "raylib.h"
#include "Log.h"

GameEngine::GameEngine()
{
	Log::print("Engine Created");
}

void GameEngine::initialize(int scWidth, int scHeight)
{
	InitWindow(scWidth, scHeight, "Game Engine");
	SetTargetFPS(60);
	Log::print("Engine Initialized");
}

void GameEngine::update()
{
}

void GameEngine::draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("idk!", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}

void GameEngine::run()
{
}

void GameEngine::shutdown()
{
	//Unload asset manager
	CloseWindow();
	Log::print("Engine Shutdown");
}
