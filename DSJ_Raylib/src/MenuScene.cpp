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
	DrawText("Go to Balls", 100, 100, 10, WHITE);
	/*DrawText("Menu Scene", 190, 200, 20, BLACK);
	Rectangle buttonRect = { 200, 100, 200, 100 };
	if (GuiButton(buttonRect, "#191#Show Message")) {
		Log::print("Button Clicked in MenuScene");
	}*/
}

void MenuScene::onLoadMenu(const LoadMenuEvent& e)
{
	Log::print(e.msg);
}