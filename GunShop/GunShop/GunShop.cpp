#include "GunShop.h"

GunShop::GunShop()
{
}

GunShop::GunShop(const GunStorage& storage)
{
	this->storage = storage;
}

GunShop::~GunShop()
{
	storage.~GunStorage();
}

GunStorage GunShop::getStorage()
{
	return storage;
}

void GunShop::addItem(Gun& newGun)
{
	storage.addItem(newGun);
}

void GunShop::removeItem(int ind)
{
	storage.removeItem(ind);
}

void GunShop::displayAll()
{
	storage.displayAll();
}

bool GunShop::loadCsv(string csvPath)
{
	return storage.loadFromCsv(csvPath);
}

bool GunShop::saveCsv(string csvPath)
{
	return storage.saveCsv(csvPath);
}
