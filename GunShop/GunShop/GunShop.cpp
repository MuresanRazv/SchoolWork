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
	pair<pair<Gun*, int>, string> newPair;
	newPair = make_pair(make_pair(newGun.Clone(), storage.getSize() - 1), "a");
	undoSt.push(newPair);
}

void GunShop::removeItem(int ind)
{
	pair<pair<Gun*, int>, string> newPair;
	newPair = make_pair(make_pair(this->storage.getAll()[ind]->Clone(), ind), "r");
	undoSt.push(newPair);
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
	if (this->undoSt.empty())
   		return false;
	else {
		pair<pair<Gun*, int>, string> newPair = undoSt.top();

		// Use dynamic cast to succesfully clone an object
		Handgun* hg = dynamic_cast<Handgun*>(undoSt.top().first.first);
		if (hg != nullptr)
			newPair.first.first = undoSt.top().first.first->Clone();

		Revolver* rv = dynamic_cast<Revolver*>(undoSt.top().first.first);
		if (rv != nullptr)
			newPair.first.first = undoSt.top().first.first->Clone();

		Rifle* rf = dynamic_cast<Rifle*>(undoSt.top().first.first);
		if (rf != nullptr)
			newPair.first.first = undoSt.top().first.first->Clone();

		Shotgun* sg = dynamic_cast<Shotgun*>(undoSt.top().first.first);
		if (sg != nullptr)
			newPair.first.first = undoSt.top().first.first->Clone();

		// Undo the operation and place the redo-object in redo stack
		if (undoSt.top().second == "r") {
			storage.insertItem(*undoSt.top().first.first->Clone(), undoSt.top().first.second);
			newPair.second = "a";
		}
		else if (undoSt.top().second == "a") {
			storage.removeItem(undoSt.top().first.second);
			newPair.second = "r";
		}
		else {
			if (hg != nullptr) {
				newPair.first.first = storage.getAll()[undoSt.top().first.second]->Clone();
				storage.editItem<Handgun>(undoSt.top().first.second, undoSt.top().first.first->Clone());
			}
			if (rv != nullptr) {
				newPair.first.first = storage.getAll()[undoSt.top().first.second]->Clone();
				storage.editItem<Revolver>(undoSt.top().first.second, undoSt.top().first.first->Clone());
			}
			if (rf != nullptr) {
				newPair.first.first = storage.getAll()[undoSt.top().first.second]->Clone();
				storage.editItem<Rifle>(undoSt.top().first.second, undoSt.top().first.first->Clone());
			}

			if (sg != nullptr) {
				newPair.first.first = storage.getAll()[undoSt.top().first.second]->Clone();
				storage.editItem<Shotgun>(undoSt.top().first.second, undoSt.top().first.first->Clone());
			}
		}
		undoSt.pop();
		redoSt.push(newPair);
	}
	return true;
}

bool GunShop::redo()
{
	if (redoSt.empty())
		return false;
	else {
 		pair<pair<Gun*, int>, string> newPair = redoSt.top();
		Handgun* hg = dynamic_cast<Handgun*>(redoSt.top().first.first);
		if (hg != nullptr)
			newPair.first.first = redoSt.top().first.first->Clone();

		Revolver* rv = dynamic_cast<Revolver*>(redoSt.top().first.first);
		if (rv != nullptr)
			newPair.first.first = redoSt.top().first.first->Clone();

		Rifle* rf = dynamic_cast<Rifle*>(redoSt.top().first.first);
		if (rf != nullptr)
			newPair.first.first = redoSt.top().first.first->Clone();

		Shotgun* sg = dynamic_cast<Shotgun*>(redoSt.top().first.first);
		if (sg != nullptr)
			newPair.first.first = redoSt.top().first.first->Clone();

		if (redoSt.top().second == "r") {
			storage.insertItem(*redoSt.top().first.first->Clone(), redoSt.top().first.second);
			newPair.second = "a";
		}
		else if (redoSt.top().second == "a") {
 			storage.removeItem(redoSt.top().first.second);
			newPair.second = "r";
		}
		else {
			if (hg != nullptr) {
				newPair.first.first = storage.getAll()[redoSt.top().first.second]->Clone();
				storage.editItem<Handgun>(redoSt.top().first.second, redoSt.top().first.first->Clone());
			}
			if (rv != nullptr) {
				newPair.first.first = storage.getAll()[redoSt.top().first.second]->Clone();
				storage.editItem<Revolver>(redoSt.top().first.second, redoSt.top().first.first->Clone());
			}
			if (rf != nullptr) {
				newPair.first.first = storage.getAll()[redoSt.top().first.second]->Clone();
				storage.editItem<Rifle>(redoSt.top().first.second, redoSt.top().first.first->Clone());
			}
			if (sg != nullptr) {
				newPair.first.first = storage.getAll()[redoSt.top().first.second]->Clone();
				storage.editItem<Shotgun>(redoSt.top().first.second, redoSt.top().first.first->Clone());
			}
		}
		redoSt.pop();
		undoSt.push(newPair);
	}
	return true;
}
