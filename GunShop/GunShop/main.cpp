#include "Tests.h"
#include "UI.h"

int main() {
	Tests* testGun = new GunTests;
	Tests* testStorage = new GunStorageTests;
	testGun->runAllTests();
	testStorage->runAllTests();
	delete testGun;
	delete testStorage;

	GunShop shop = GunShop();
	UI ui = UI(shop);

	ui.display();
	
	ui.~UI();
	shop.~GunShop();
	
	return 0;
}
