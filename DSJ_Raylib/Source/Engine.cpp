#include "Engine.h"
#include "raylib.h"
#include "Log.h"
#include "SceneManager.h"

Engine::Engine()
{
	Log::print("Engine Created");
}

void Engine::initialize(int scWidth, int scHeight)
{
	InitWindow(scWidth, scHeight, "Game Engine");
	SetTargetFPS(60);
	Log::print("Engine Initialized");
	SceneManager sceneManager;
}

void Engine::run()
{
	//sceneManager.draw();
}

void Engine::update()
{
	//sceneManager.update();
}

void Engine::render()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("idk!", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}

void Engine::shutdown()
{
	//Unload asset manager
	CloseWindow();
	Log::print("Engine Shutdown");
}
