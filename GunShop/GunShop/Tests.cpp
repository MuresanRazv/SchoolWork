#include "Tests.h"

void GunTests::runAllTests()
{
	creationTest();
	gettersSettersTest();
}

int GunTests::creationTest()
{
	Gun* g1 = new Handgun(5, 2, "Colt", automaticHg);
	Gun* g2 = new Revolver(5, 4, "Rv", singleAction);

	assert(g1->getName() == "Colt");
	assert(g2->getName() == "Rv");

	assert(g1->getBulletCapacity() == 5);
	assert(g2->getBulletCapacity() == 5);
	
	assert(g1->getWeight() == 2);
	assert(g2->getWeight() == 4);

	Handgun* hg = dynamic_cast<Handgun*>(g1);
	assert(hg->getFunc() == automaticHg);

	Revolver* rv = dynamic_cast<Revolver*>(g2);
	assert(rv->getFunc() == singleAction);

	delete g1;
	delete g2;

	return 0;
}

int GunTests::gettersSettersTest()
{
	Gun* g = new Rifle(10, 5, "SKS", semiAutomaticRf);
	Rifle* rf = dynamic_cast<Rifle*>(g);

	rf->setBulletCapacity(5);
	rf->setWeight(5);
	rf->setName("rf");
	rf->setFunc(leverActionRf);

	assert(rf->getBulletCapacity() == 5);
	assert(rf->getWeight() == 5);
	assert(rf->getFunc() == leverActionRf);
	assert(rf->getName() == "rf");

	delete g;

	return 0;
}

void GunStorageTests::runAllTests()
{
	creationTest();
	gettersSettersTest();
	operationsTest();
}

int GunStorageTests::creationTest()
{
	GunStorage guns = GunStorage();
	assert(guns.getSize() == 0);

	return 0;
}

int GunStorageTests::gettersSettersTest()
{
	GunStorage guns = GunStorage();

	Gun* g = new Handgun(5, 3, "Colt", semiAutomaticHg);
	Handgun* hg = dynamic_cast<Handgun*>(g);

	guns.addItem(*g);

	Handgun* storageHg = dynamic_cast<Handgun*>(guns.getAll()[0]);

	assert(guns.getSize() == 1);
	assert(storageHg->getBulletCapacity() == hg->getBulletCapacity());
	assert(storageHg->getName() == hg->getName());
	assert(storageHg->getFunc() == hg->getFunc());
	assert(storageHg->getWeight() == hg->getWeight());

	Gun* newG = new Handgun(3, 2, "usp", automaticHg);
	Gun* newG2 = new Handgun(3, 2, "usp", automaticHg);
	vector<Gun*> newSt;
	
	newSt.push_back(newG);
	newSt.push_back(newG2);

	guns.setStorage(newSt);

	assert(guns.getSize() == 2);

	delete g;
	delete newSt[0];
	delete newSt[1];

	return 0;
}

int GunStorageTests::operationsTest()
{
	GunStorage guns = GunStorage();

	Gun* g1 = new Handgun(5, 2, "Colt", automaticHg);
	Gun* g2 = new Revolver(5, 4, "Rv", singleAction);
	Gun* g3 = new Rifle(10, 5, "SKS", semiAutomaticRf);
	Gun* g4 = new Shotgun(8, 10, "Shotgun", leverActionSg);
	Gun* editG2 = new Revolver(3, 3, "newRv", doubleAction);

	guns.addItem(*g1);
	guns.addItem(*g2);
	guns.addItem(*g3);
	guns.addItem(*g4);

	guns.editItem<Revolver>(1, editG2);

	Revolver* editedRv = dynamic_cast<Revolver*>(guns.getAll()[1]);

	assert(editedRv->getBulletCapacity() == 3);
	assert(editedRv->getWeight() == 3);
	assert(editedRv->getFunc() == doubleAction);
	assert(editedRv->getName() == "newRv");

	assert(guns.getFunctionInString(1) == "Double Action");
	assert(guns.getTypeInString(1) == "Revolver");

	guns.removeItem(0);

	assert(guns.getSize() == 3);
	assert(guns.getAll()[0]->getName() == "newRv");
	
	delete g1;
	delete g2;
	delete g3;
	delete g4;
	delete editG2;

	return 0;
}
