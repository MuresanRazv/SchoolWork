#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "GunShop.h"
#include "Exceptions.h"
using namespace std;

class UI : public GunShop {
private:
	GunShop shop;
	bool running;

public:
	// Constructors
	UI();
	UI(const GunShop& newShop);

	// Desctructor
	~UI();

	// Operations
	hgFunction convertToHg(string key);
	rvFunction convertToRv(string key);
	rfFunction convertToRf(string key);
	sgFunction convertToSg(string key);

	bool doOperation(string key);

	void displayHeader();
	void displayAll();
	void displayMenu();
	void display();
};