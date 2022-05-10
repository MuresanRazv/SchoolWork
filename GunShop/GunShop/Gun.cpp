#include "Gun.h"
#include "string"

Gun::Gun()
{
	bulletCapacity = 0;
	weight = 0;
	name = "None";
}

Gun* Gun::Clone()
{
	return nullptr;
}

unsigned int Gun::getBulletCapacity()
{
	return bulletCapacity;
}

unsigned int Gun::getWeight()
{
	return weight;
}

string Gun::getName()
{
	return name;
}

void Gun::setBulletCapacity(unsigned int newBulletCapacity)
{
	bulletCapacity = newBulletCapacity;
}

void Gun::setWeight(unsigned int newWeight)
{
	weight = newWeight;
}

void Gun::setName(string newName)
{
	this->name = newName;
}

Gun::~Gun()
{
}

void Gun::display()
{
	cout << setw(5) << "Bullet Capacity: " << bulletCapacity << '\n' << "Weight: " << weight << '\n';
}

Handgun::Handgun()
{
	func = hgFunction();
}

Handgun::Handgun(unsigned int bulletCapacity, unsigned int weight, string name, hgFunction func)
{
	this->setBulletCapacity(bulletCapacity);
	this->setWeight(weight);
	this->setName(name);
	this->func = func;
}

Handgun::~Handgun()
{
}

hgFunction Handgun::getFunc()
{
	return func;
}

void Handgun::setFunc(hgFunction newFunc)
{
	func = newFunc;
}

string Handgun::displayFunc()
{
	string result = "";

	if (func == 0)
		result += "Semi Automatic";
	if (func == 1)
		result += "Automatic";

	return result;
}

void Handgun::display()
{
	cout << setw(20) << "Handgun |" << setw(20) << this->getName() + " |" << setw(20) << std::to_string(this->getBulletCapacity()) + " |" << setw(20) << std::to_string(this->getWeight()) + " |" << setw(20) << this->displayFunc() + " |" << std::endl;
}

Revolver::Revolver()
{
	func = rvFunction();
}

Revolver::Revolver(unsigned int bulletCapacity, unsigned int weight, string name, rvFunction func)
{
	this->setBulletCapacity(bulletCapacity);
	this->setWeight(weight);
	this->setName(name);
	this->func = func;
}

Revolver::~Revolver()
{
}

rvFunction Revolver::getFunc()
{
	return func;
}

void Revolver::setFunc(rvFunction newFunc)
{
	func = newFunc;
}

string Revolver::displayFunc()
{
	string result = "";

	if (func == 0)
		result += "Single Action";
	if (func == 1)
		result += "Double Action";

	return result;
}

void Revolver::display()
{
	cout << setw(20) << "Revolver |" << setw(20) << this->getName() + " |" << setw(20) << std::to_string(this->getBulletCapacity()) + " |" << setw(20) << std::to_string(this->getWeight()) + " |" << setw(20) << this->displayFunc() + " |" << std::endl;
}

Rifle::Rifle()
{
	func = rfFunction();
}

Rifle::Rifle(unsigned int bulletCapacity, unsigned int weight, string name, rfFunction func)
{
	this->setBulletCapacity(bulletCapacity);
	this->setWeight(weight);
	this->setName(name);
	this->func = func;
}

Rifle::~Rifle()
{
}

rfFunction Rifle::getFunc()
{
	return func;
}

void Rifle::setFunc(rfFunction newFunc)
{
	func = newFunc;
}

string Rifle::displayFunc()
{
	string result = "";

	if (func == 0)
		result += "Lever Action";
	if (func == 1)
		result += "Bolt Action";
	if (func == 2)
		result += "Semi Automatic";

	return result;
}

void Rifle::display()
{
	cout << setw(20) << "Rifle |" << setw(20) << this->getName() + " |" << setw(20) << std::to_string(this->getBulletCapacity()) + " |" << setw(20) << std::to_string(this->getWeight()) + " |" << setw(20) << this->displayFunc() + " |" << std::endl;
}

Shotgun::Shotgun()
{
	func = sgFunction();
}

Shotgun::Shotgun(unsigned int bulletCapacity, unsigned int weight, string name, sgFunction func)
{
	this->setBulletCapacity(bulletCapacity);
	this->setWeight(weight);
	this->setName(name);
	this->func = func;
}

Shotgun::~Shotgun()
{
}

sgFunction Shotgun::getFunc()
{
	return func;
}

void Shotgun::setFunc(sgFunction newFunc)
{
	func = newFunc;
}

string Shotgun::displayFunc()
{
	string result = "";

	if (func == 0)
		result += "Break Action";
	if (func == 1)
		result += "Lever Action";
	if (func == 2)
		result += "Pump Action";
	if (func == 3)
		result += "Semi Automatic";

	return result;
}

void Shotgun::display()
{
	cout << setw(20) << "Shotgun |" << setw(20) << this->getName() + " |" << setw(20) << std::to_string(this->getBulletCapacity()) + " |" << setw(20) << std::to_string(this->getWeight()) + " |" << setw(20) << this->displayFunc() + " |" << std::endl;
}
