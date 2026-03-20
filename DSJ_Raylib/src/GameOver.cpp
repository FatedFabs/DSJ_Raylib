#include "GameOver.h"
#include "PlayScene.h"
#include "MenuScene.h"
#include "SceneManager.h"
#include "raylib.h"
#include "raygui.h"

GameOver& GameOver::instance()
{
	static GameOver instance;
	return instance;
}

void GameOver::load()
{
	endScore = PlayScene::instance().score;
	bgImage = LoadImage("Assets/Textures/background.png");
	bgTexture = LoadTextureFromImage(bgImage);
}

void GameOver::unload()
{
}

void GameOver::update()
{
}

void GameOver::draw()
{
	EndMode2D();
	DrawTexture(bgTexture, 0, 0, WHITE);

	DrawText("Game Over", 242, 60, 56, BLACK);
	DrawText("Score: " + endScore, 174, 142, 28, BLACK);

	Rectangle buttonRect = { 300, 350, 200, 50 };
	if (GuiButton(buttonRect, "#191#Back to Main Menu")) {
		SceneManager::instance().changeScene(&MenuScene::instance());
	}
}
