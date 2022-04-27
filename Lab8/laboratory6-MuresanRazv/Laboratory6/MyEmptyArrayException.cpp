#include "MyEmptyArrayException.h"

MyEmptyArrayException::MyEmptyArrayException()
{
}

const char* MyEmptyArrayException::what() const throw()
{
    return "Empty array!";
}
