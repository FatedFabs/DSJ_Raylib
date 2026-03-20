#pragma once
#include "Scene.h"
#include "EventManager.h"
#include <string>

class InstructionsScene : public Scene
{
public:
	static InstructionsScene& instance();

	void load() override;
	void unload() override;
	void update() override;
	void draw() override;

private:
	Image bgImage;
	Texture2D bgTexture;
};