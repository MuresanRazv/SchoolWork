#pragma once
#include "GunStorage.h"

class GunShop : public GunStorage {
private:
	GunStorage storage;
	// TODO: finish implementation of Undo/Redo, besides the objects i'm storing in the stack,
	// I also have to store the indice and operation that was used so that I can Undo/Redo the
	// operation properly
	stack<Gun> undoSt;
	stack<Gun> redoSt;

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
		undoSt.push(*storage.getAll()[ind]);
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
