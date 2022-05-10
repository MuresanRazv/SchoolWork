#pragma once
#include "GunStorage.h"

class GunShop : public GunStorage {
private:
	GunStorage storage;
	stack<pair<pair<Gun*, int>, string>> undoSt;
	stack<pair<pair<Gun*, int>, string>> redoSt;

public:
	// Constructors
	GunShop();
	GunShop(const GunStorage& storage);

	// Destructor
	~GunShop();

	// Getter
	GunStorage getStorage();

	// Operations
	void addItem(Gun& newGun);
	template <typename GunType>
	void editItem(int ind, Gun* newGun) {
		pair<pair<Gun*, int>, string> newPair;
		newPair = make_pair(make_pair(this->storage.getAll()[ind]->Clone(), ind), "e");
		undoSt.push(newPair);
		storage.editItem<GunType>(ind, newGun);
	}
	void removeItem(int ind);
	void displayAll();

	// CSV
	bool loadCsv(string csvPath);
	bool saveCsv(string csvPath);

	// Undo/Redo
	bool undo();
	bool redo();
};
