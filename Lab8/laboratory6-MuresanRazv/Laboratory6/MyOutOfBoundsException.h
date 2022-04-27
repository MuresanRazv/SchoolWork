#pragma once
#include <exception>
#include <string>

class MyOutOfBoundsException : public std::exception {
public:
	MyOutOfBoundsException();
	MyOutOfBoundsException(int lowerBound, int upperBound, int idx);

	const char* what() const throw ();
private:

	int lowerBound;
	int upperBound;
	int idx;

};