#include "../Include/PlayScene.h"
#include "../Include/SceneManager.h"
#include "../Include/raylib.h"
#include "../Include/raygui.h"
#include "../Include/Log.h"
#include <fstream>

PlayScene& PlayScene::instance()
{
	static PlayScene instance;
	return instance;
}

void PlayScene::load()
{


}

void PlayScene::unload()
{
}

void PlayScene::update()
{
}

void PlayScene::draw()
{
}