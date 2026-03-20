#include "MenuScene.h"
#include "PlayScene.h"
#include "InstructionsScene.h"
#include "SceneManager.h"
#include "raylib.h"
#include "raygui.h"
#include "Log.h"

MenuScene& MenuScene::instance()
{
	static MenuScene instance;
	return instance;
}

void MenuScene::load()
{
	LoadMenuEvent event;
	eventManager.emit(event);
	bgImage = LoadImage("Assets/Textures/background.png");
	bgTexture = LoadTextureFromImage(bgImage);
}

void MenuScene::unload()
{
}

void MenuScene::update()
{
	
}

void MenuScene::draw()
{
	EndMode2D();
	DrawTexture(bgTexture, 0, 0, WHITE);

	DrawText("Happy Birds", 242, 60, 56, BLACK);

	Rectangle playButton = { 300, 275, 200, 50 };
	if (GuiButton(playButton, "#191#Play")){
		SceneManager::instance().changeScene(&PlayScene::instance());
	}

	Rectangle instructionsButton = { 300, 350, 200, 50 };
	if (GuiButton(instructionsButton, "#191#Instructions")){
		SceneManager::instance().changeScene(&InstructionsScene::instance());
	}
}

void MenuScene::onLoadMenu(const LoadMenuEvent& e)
{
	Log::print(e.msg);
}