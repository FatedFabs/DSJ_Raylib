#pragma once
#include "Scene.h"
#include "EventManager.h"
#include <string>

struct LoadMenuEvent {
	std::string msg = "Menu Loaded";
};

class PlayScene : public Scene
{
public:
	static PlayScene& instance();

	void load() override;
	void unload() override;
	void update() override;
	void draw() override;

	void onLoadMenu(const LoadMenuEvent& e);

private:
	PlayScene() { eventManager.subscribe(this, &PlayScene::onLoadMenu); }
};
