#pragma once
#include <iostream>
#include <cassert>
#include "GunShop.h";

class Tests {
public:
	virtual void runAllTests() = 0;
};

class GunTests : public Tests {
public:
	void runAllTests();
	static int creationTest();
	static int gettersSettersTest();
};

class GunStorageTests : public Tests {
	void runAllTests();
	static int creationTest();
	static int gettersSettersTest();
	static int operationsTest();
};