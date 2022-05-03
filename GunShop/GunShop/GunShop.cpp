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
	undoSt.push(newGun);
}

void GunShop::removeItem(int ind)
{
	undoSt.push(*this->storage.getAll()[ind]);
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

bool GunShop::undo()
{
	if (undoSt.empty())
		return false;
	else {
		redoSt.push(undoSt.top());
		undoSt.pop();
	}
	return true;
}

bool GunShop::redo()
{
	if (redoSt.empty())
		return false;
	else {
		undoSt.push(redoSt.top());
		redoSt.pop();
	}
	return true;
}
