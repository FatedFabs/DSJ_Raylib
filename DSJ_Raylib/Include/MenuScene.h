#pragma once
#include "Scene.h"
#include "EventManager.h"
#include <string>

struct LoadMenuEvent {
	std::string msg = "Menu Loaded";
};

class MenuScene : public Scene
{
public:
	static MenuScene& instance();

	void load() override;
	void unload() override;
	void update() override;
	void draw() override;

	void onLoadMenu(const LoadMenuEvent& e);

private:
	MenuScene() { eventManager.subscribe(this, &MenuScene::onLoadMenu); }
	Image bgImage;
	Texture2D bgTexture;
};

