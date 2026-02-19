#include "../Include/MemoryManager.h"
#include <iostream>

MemoryManager* MemoryManager::instance = nullptr;
MemoryManager* MemoryManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MemoryManager();
		instance->init();
	}
	return instance;
}

void* MemoryManager::alloc(size_t size)
{
	return nullptr;
}

void MemoryManager::free(void* ptr)
{
}

MemoryManager::MemoryManager()
{

}

MemoryManager::~MemoryManager()
{
}

void MemoryManager::init()
{
	std::cout << "MemoryManager::init()" << std::endl;
}