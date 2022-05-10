#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <fstream>
#include "Gun.h"
using namespace std;

class GunStorage {
private:
	vector<Gun*> guns;

public:
	// Constructors
	GunStorage();
	GunStorage(const GunStorage& other);

	// Destructor
	~GunStorage();

	// Getters
	int getSize();
	vector<Gun*> getAll();

	// Setter
	void setStorage(vector<Gun*> newStorage);

	// Display
	void displayAll();

	// Operations
	void addItem(Gun& newGun);
	void insertItem(Gun& newGun, int ind);
	template <typename GunType>
	void editItem(int ind, Gun* newGun) {
		guns[ind]->~Gun();
		guns[ind] = new GunType();
		GunType* hg = dynamic_cast<GunType*>(guns[ind]), * newHg = dynamic_cast<GunType*>(newGun);
		if (hg != nullptr && newHg != nullptr) {
			hg->setFunc(newHg->getFunc());
			hg->setName(newHg->getName());
			hg->setWeight(newHg->getWeight());
			hg->setBulletCapacity(newHg->getBulletCapacity());
		}
	}
	void removeItem(int ind);
	
	// CSV files
	std::vector<string> tokenize(string str, char delimiter);
	string getTypeInString(int ind);
	string getFunctionInString(int ind);
	bool loadFromCsv(string csvPath);
	bool saveCsv(string csvPath);

};