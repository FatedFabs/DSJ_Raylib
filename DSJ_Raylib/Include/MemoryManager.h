#pragma once
#include <iostream>

class MemoryManager
{
public:
	static MemoryManager* GetInstance();
	
	void* alloc(size_t size);
	void free(void* ptr);

private:
	static MemoryManager* instance;
	MemoryManager();
	~MemoryManager();
	MemoryManager(const MemoryManager& other) = delete;
	MemoryManager& operator=(const MemoryManager& other) = delete;
	
	void init();
};

