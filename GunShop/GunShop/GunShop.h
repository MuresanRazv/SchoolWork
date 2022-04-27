#pragma once
#include "GunStorage.h"

class GunShop : public GunStorage {
private:
	GunStorage storage;

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
		storage.editItem<GunType>(ind, newGun);
	}
	void removeItem(int ind);
	void displayAll();

	// CSV
	bool loadCsv(string csvPath);
	bool saveCsv(string csvPath);
};
