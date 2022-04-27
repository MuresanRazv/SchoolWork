#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

class invalidKeyException : public exception {
public:
	invalidKeyException();
	invalidKeyException(string validKeys);

	const char* what() const throw ();

private:
	string validKeys;
};

class invalidIndException : public exception {
public:
	invalidIndException();

	const char* what() const throw ();
};