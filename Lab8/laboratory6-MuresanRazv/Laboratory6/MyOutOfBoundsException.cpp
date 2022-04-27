#include "MyOutOfBoundsException.h"

MyOutOfBoundsException::MyOutOfBoundsException()
{
}

MyOutOfBoundsException::MyOutOfBoundsException(int lowerBound, int upperBound, int idx)
{
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    this->idx = idx;
}

const char* MyOutOfBoundsException::what() const throw()
{
    return "Out of bounds!";
}
