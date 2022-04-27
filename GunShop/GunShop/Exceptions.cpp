#include "Exceptions.h"

invalidKeyException::invalidKeyException()
{
}

invalidKeyException::invalidKeyException(string validKeys)
{
	this->validKeys = validKeys;
}

const char* invalidKeyException::what() const throw()
{
	return validKeys.c_str();
}

invalidIndException::invalidIndException()
{
}

const char* invalidIndException::what() const throw()
{
	return "Invalid value!";
}
