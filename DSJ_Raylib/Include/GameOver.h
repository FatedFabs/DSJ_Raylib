#pragma once
#include "Scene.h"

class GameOver : public Scene
{
public:
	static GameOver& instance();

	void load() override;
	void unload() override;
	void update() override;
	void draw() override;

	void SetEndScore(int _score) { endScore = _score; }

private:
	Image bgImage;
	Texture2D bgTexture;
	int endScore;
};