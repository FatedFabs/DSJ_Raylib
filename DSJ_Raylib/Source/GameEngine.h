#pragma once
class GameEngine
{
public:
	GameEngine();

	void initialize(int scWidth, int scHeight);
	void update();
	void draw();
	void run();
	void shutdown();
};