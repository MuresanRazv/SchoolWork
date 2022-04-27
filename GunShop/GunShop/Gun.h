#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using std::string;
using std::cout;
using std::setw;

enum gunType {
	handgun,
	revolver,
	rifle,
	shotgun
};

enum hgFunction {
	semiAutomaticHg,
	automaticHg,
};

enum rvFunction {
	singleAction,
	doubleAction,
};

enum rfFunction {
	leverActionRf,
	boltAction,
	semiAutomaticRf
};

enum sgFunction {
	breakAction,
	leverActionSg,
	pumpAction,
	semiAutomatic
};

class Gun {
private:
	string name;
	unsigned int bulletCapacity;
	unsigned int weight;
public:
	// Constructor 
	Gun();

	// Destructor
	virtual ~Gun();

	virtual void display();

	// Getters
	unsigned int getBulletCapacity();
	unsigned int getWeight();
	string getName();

	// Setters
	void setWeight(unsigned int newWeight);
	void setName(string newName);
	void setBulletCapacity(unsigned int newBulletCapacity);

};

class Handgun : public Gun {
private:
	hgFunction func;

public:
	// Constructors
	Handgun();
	Handgun(unsigned int bulletCapacity, unsigned int weight, string name, hgFunction func);

	// Destructor
	~Handgun();

	// Getters
	hgFunction getFunc();

	// Setters
	void setFunc(hgFunction newFunc); 
	
	// Display
	string displayFunc();
	void display();
};

class Revolver : public Gun {
private:
	rvFunction func;

public:
	// Constructors
	Revolver();
	Revolver(unsigned int bulletCapacity, unsigned int weight, string name, rvFunction func);

	// Destructor
	~Revolver();

	// Getters
	rvFunction getFunc();

	// Setters
	void setFunc(rvFunction newFunc);

	// Display
	string displayFunc();
	void display();
};

class Rifle : public Gun {
private:
	rfFunction func;

public:
	// Constructors
	Rifle();
	Rifle(unsigned int bulletCapacity, unsigned int weight, string name, rfFunction func);

	// Destructor
	~Rifle();

	// Getters
	rfFunction getFunc();

	// Setters
	void setFunc(rfFunction newFunc);

	// Display
	string displayFunc();
	void display();
};

class Shotgun : public Gun {
private:
	sgFunction func;

public:
	// Constructors
	Shotgun();
	Shotgun(unsigned int bulletCapacity, unsigned int weight, string name, sgFunction func);

	// Destructor
	~Shotgun();

	// Getters
	sgFunction getFunc();

	// Setters
	void setFunc(sgFunction newFunc);

	// Display
	string displayFunc();
	void display();
};