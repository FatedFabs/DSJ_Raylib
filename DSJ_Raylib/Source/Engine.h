#pragma once

class Engine
{
public:
	Engine();

	void initialize(int scWidth, int scHeight);
	void run();
	void update();
	void render();
	void shutdown();
};