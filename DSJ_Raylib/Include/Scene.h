#pragma once
#include "EventManager.h"

class Scene
{
public:
	EventManager& eventManager = EventManager::instance();;
	virtual ~Scene() = default;
	
	virtual void load() = 0;
	virtual void unload() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

