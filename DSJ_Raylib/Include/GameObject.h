#pragma once
#include "raylib.h"
#include "Component.h"
#include <vector>
#include <memory>
typedef std::shared_ptr<Component>  ptrComponent;
class GameObject
{
public:
	bool enabled;
	int id;

	GameObject();
	~GameObject();

	void Start();
	void Update(float deltaTime);
	void Draw(float deltaTime);

	void AddComponent(ptrComponent newComp);
	void RemoveComponent();
private:
	std::vector<ptrComponent> components;

	friend class Component;
};

