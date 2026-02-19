#include "../Include/GameObject.h"

GameObject::GameObject()
{
	id = 0;
	enabled = true;
}

GameObject::~GameObject()
{
}

void GameObject::Start()
{
}

void GameObject::Update(float deltaTime)
{
	for (auto& comp : components)
	{
		comp->Update(deltaTime);
	}
}

void GameObject::Draw(float deltaTime)
{
	for (auto& comp : components)
	{
		if (comp->ShouldDraw())
		{
			comp->Draw(deltaTime);
		}
	}
}

void GameObject::AddComponent(ptrComponent newComp)
{
	components.push_back(newComp);
}

void GameObject::RemoveComponent()
{
}
