#pragma once

class SceneManager
{
public:
	static SceneManager& instance();
	SceneManager();

	void update();
	void draw();
};