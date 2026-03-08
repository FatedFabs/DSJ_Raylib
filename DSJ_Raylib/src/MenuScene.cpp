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
	bgImage = LoadImage("Assets/Textures/LuigiD.png");
	bgTexture = LoadTextureFromImage(bgImage);
}

void MenuScene::unload()
{
}

void MenuScene::update()
{
	if (IsKeyPressed(KEY_SPACE)) {
		SceneManager::instance().changeScene(&PlayScene::instance());
	}
}

void MenuScene::draw()
{
	DrawTexture(bgTexture, -10, -10, WHITE);
	DrawText("Go to Balls", 100, 100, 10, WHITE);
	DrawText("Menu", -10, -10, 1, BLACK);
	DrawText("Space to start", -10, 0, 1, BLACK);
	Rectangle buttonRect = { 200, 100, 200, 100 };
	if (GuiButton(buttonRect, "#191#Show Message")) {
		Log::print("Button Clicked in MenuScene");
	}
}

void MenuScene::onLoadMenu(const LoadMenuEvent& e)
{
	Log::print(e.msg);
}