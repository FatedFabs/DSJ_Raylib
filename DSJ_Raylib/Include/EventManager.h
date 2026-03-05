#pragma once
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <functional>
#include <algorithm>

class EventManager
{
public:
	// Acción que se ejecuta al emitir un evento
	using Callback = std::function<void(const void*)>; 
	// Objeto + acción asociada
	using Listener = std::pair<void*, Callback>;

	//singleton
	static EventManager& instance() {
		static EventManager instance;
		return instance;
	}

	template<typename Event, typename Object>
	void subscribe(Object* object, void(Object::* method)(const Event&)){
		auto eventType = std::type_index(typeid(Event));
		Callback callback = [object, method](const void* evt) {
			const Event* event = static_cast<const Event*>(evt);
			(object->*method)(*event);
			};
		listeners[eventType].push_back({ object, callback });
	}

	template<typename Event>
	void unsubscribe(void* object) {
		auto eventType = std::type_index(typeid(Event));
		auto it = listeners.find(eventType);
		if (it == listeners.end()) return;

		auto& list = it->second;
		list.erase(std::remove_if(list.begin(), list.end(),
			[object](const Listener& l) { return l.first == object; }),
			list.end());
	}

	template<typename Event>
	void emit(const Event& event) {
		auto eventType = std::type_index(typeid(Event));
		auto it = listeners.find(eventType);
		if (it == listeners.end()) return;

		for (const Listener& l : it->second)
			l.second(&event);
	}
private:
	std::unordered_map<std::type_index, std::vector<Listener>> listeners;
};

