#ifndef Log
#endif !Log

#include <iostream>
#include <string>
class Log
{
public:
	static void print(const std::string& text) {
		std::cout << text << "\n";
	};
};