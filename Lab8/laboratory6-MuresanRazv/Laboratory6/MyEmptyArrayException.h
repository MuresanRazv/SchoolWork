#pragma once
#include <exception>
#include <string>

class MyEmptyArrayException : public std::exception {
public:
	MyEmptyArrayException();
	const char* what() const throw ();
	
};