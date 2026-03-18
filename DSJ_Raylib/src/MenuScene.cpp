#include "MenuScene.h"
#include "PlayScene.h"
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
	DrawText("Happy Birds", 242, 25, 56, BLACK);
	DrawText("Drag the bird and release to shoot", 174, 142, 28, BLACK);
	DrawText("Press space to reset", 250, 185, 28, BLACK);
	DrawText("Press g to save game", 250, 228, 28, BLACK);
	DrawText("Press l to load game", 250, 271, 28, BLACK);
	Rectangle buttonRect = { 300, 350, 200, 50 };
	if (GuiButton(buttonRect, "#191#Play")) {
		Log::print("Button Clicked in MenuScene");
		SceneManager::instance().changeScene(&PlayScene::instance());
	}
}

void MenuScene::onLoadMenu(const LoadMenuEvent& e)
{
	Log::print(e.msg);
}