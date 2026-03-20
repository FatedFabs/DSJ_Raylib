#include "InstructionsScene.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "SceneManager.h"
#include "raylib.h"
#include "raygui.h"
#include "Log.h"

InstructionsScene& InstructionsScene::instance()
{
	static InstructionsScene instance;
	return instance;
}

void InstructionsScene::load()
{
	bgImage = LoadImage("Assets/Textures/background.png");
	bgTexture = LoadTextureFromImage(bgImage);
}

void InstructionsScene::unload()
{
	
}

void InstructionsScene::update()
{
	
}

void InstructionsScene::draw()
{
	EndMode2D();
	DrawTexture(bgTexture, 0, 0, WHITE);

	DrawText("Instructions", 242, 60, 56, BLACK);
	DrawText("Drag the bird and release to shoot", 174, 142, 28, BLACK);
	DrawText("Press space to reset", 250, 185, 28, BLACK);
	DrawText("Press g to save game", 250, 228, 28, BLACK);
	DrawText("Press l to load game", 250, 271, 28, BLACK);

	Rectangle buttonRect = { 300, 350, 200, 50 };
	if (GuiButton(buttonRect, "#191#Back to Main Menu")) {
		SceneManager::instance().changeScene(&MenuScene::instance());
	}
}