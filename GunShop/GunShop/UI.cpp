#include "UI.h"

UI::UI()
{
	shop = GunShop();
	running = true;
}

UI::UI(const GunShop& newShop)
{
	shop = newShop;
	running = true;
}

UI::~UI()
{
	shop.~GunShop();
}

hgFunction UI::convertToHg(string key)
{
	if (key == "sm")
		return semiAutomaticHg;
	if (key == "a")
		return automaticHg;
}

rvFunction UI::convertToRv(string key)
{
	if (key == "s")
		return singleAction;
	if (key == "d")
		return doubleAction;
}

rfFunction UI::convertToRf(string key)
{
	if (key == "l")
		return leverActionRf;
	if (key == "b")
		return boltAction;
	if (key == "s")
		return semiAutomaticRf;
}

sgFunction UI::convertToSg(string key)
{
	if (key == "b")
		return breakAction;
	if (key == "l")
		return leverActionSg;
	if (key == "p")
		return pumpAction;
	if (key == "s")
		return semiAutomatic;
}

bool UI::doOperation(string key)
{
	if (key == "A" || key == "a")
	{
		string gunKey;
		bool valid = false;

		while (!valid) {
			try {
				cout << setw(5) << "Type of weapon (handgun = h, revolver = rv, rifle = rf, shotgun = sg) ";
				cin >> gunKey; cout << endl;
				if (gunKey != "h" && gunKey != "rv" && gunKey != "rf" && gunKey != "sg")
					throw invalidKeyException("Invalid key! Valid keys are: h, rv, rf and sg");
				else
					valid = true;
			}
			catch (invalidKeyException& e) {
				cout << e.what() << '\n';
			}
		}

		int bulletCapacity;
		cout << setw(5) << "Bullet capacity "; cin >> bulletCapacity; cout << endl;

		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << setw(5) << "Invalid input type! Please input a number." << endl;
			cin >> bulletCapacity;
		}

		int weight;
		cout << setw(5) << "Weight "; cin >> weight; cout << endl;

		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << setw(5) << "Invalid input type! Please input a number." << endl;
			cin >> weight;
		}

		string name;
		cout << setw(5) << "Name "; cin >> name; cout << endl;

		// Handgun validation

		valid = false;
		if (gunKey == "h") {
			hgFunction gunFunc;

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Semi Automatic = sm, automatic = a)";
					cin >> function; cout << endl;
					if (function != "sm" && function != "a")
						throw invalidKeyException("Invalid key! Valid keys are: sm, a");
					else {
						valid = true;
						gunFunc = convertToHg(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Handgun(bulletCapacity, weight, name, gunFunc);
			shop.addItem(*newGun);
		}

		// Revolver validation

		if (gunKey == "rv") {
			rvFunction gunFunc = rvFunction();

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Single Action = s, Double Action = d)";
					cin >> function; cout << endl;
					if (function != "s" && function != "d")
						throw invalidKeyException("Invalid key! Valid keys are: s, d");
					else {
						valid = true;
						gunFunc = convertToRv(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Revolver(bulletCapacity, weight, name, gunFunc);
			shop.addItem(*newGun);
		}

		// Rifle validation

		if (gunKey == "rf") {
			rfFunction gunFunc = rfFunction();

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Lever Action = l, Bolt Action = b, Semi Automatic = s)";
					cin >> function; cout << endl;
					if (function != "l" && function != "b" && function != "s")
						throw invalidKeyException("Invalid key! Valid keys are: l, b, s");
					else {
						valid = true;
						gunFunc = convertToRf(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Rifle(bulletCapacity, weight, name, gunFunc);
			shop.addItem(*newGun);
		}

		// Shotgun validation

		if (gunKey == "sg") {
			sgFunction gunFunc = sgFunction();

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Break Action = b, Lever Action = l, Pump Action = p, Semi Automatic = s)";
					cin >> function; cout << endl;
					if (function != "b" && function != "l" && function != "p" && function != "s")
						throw invalidKeyException("Invalid key! Valid keys are: b, l, p, s");
					else {
						valid = true;
						gunFunc = convertToSg(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Shotgun(bulletCapacity, weight, name, gunFunc);
			shop.addItem(*newGun);
		}

		cout << setw(5) << "Gun succesfully added!" << endl;
		return true;
	}
	if (key == "R" || key == "r") {
		int ind;
		bool valid = false;

		if (shop.getStorage().getSize() > 0) {
			while (!valid) {
				try {
					displayAll();
					cout << "Input number of gun you want to remove (max = " << shop.getStorage().getSize() << ") ";
					cin >> ind; cout << endl;

					if (!std::cin.good())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << setw(5) << "Invalid input type! Please input a number." << endl;
					}
					else {
						if (ind > shop.getStorage().getSize())
							throw invalidIndException();
						else
							valid = true;
					}
				}
				catch (invalidIndException& e) {
					cout << e.what() << endl;
				}
			}

			shop.removeItem(ind - 1);

			cout << "Gun removed succesfully!" << endl;

			return true;
		}
		else
			cout << setw(5) << "The shop is empty!" << endl;
	}

	if (key == "M" || key == "m") {
		string gunKey;
		int ind;
		bool valid = false;

		while (!valid) {
			try {
				displayAll();
				cout << "Input number of gun you want to edit (max = " << shop.getStorage().getSize() << ") ";
				cin >> ind; cout << endl;

				if (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << setw(5) << "Invalid input type! Please input a number." << endl;
				}
				else {
					if (ind > shop.getStorage().getSize())
						throw invalidIndException();
					else
						valid = true;
				}
			}
			catch (invalidIndException& e) {
				cout << e.what() << endl;
			}
		}

		valid = false;

		while (!valid) {
			try {
				cout << setw(5) << "Type of weapon (handgun = h, revolver = rv, rifle = rf, shotgun = sg) ";
				cin >> gunKey; cout << endl;
				if (gunKey != "h" && gunKey != "rv" && gunKey != "rf" && gunKey != "sg")
					throw invalidKeyException("Invalid key! Valid keys are: h, rv, rf and sg");
				else
					valid = true;
			}
			catch (invalidKeyException& e) {
				cout << e.what() << '\n';
			}
		}

		int bulletCapacity;
		cout << setw(5) << "Bullet capacity "; cin >> bulletCapacity; cout << endl;

		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << setw(5) << "Invalid input type! Please input a number." << endl;
			cin >> bulletCapacity;
		}

		int weight;
		cout << setw(5) << "Weight "; cin >> weight; cout << endl;

		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << setw(5) << "Invalid input type! Please input a number." << endl;
			cin >> weight;
		}

		string name;
		cout << setw(5) << "Name "; cin >> name; cout << endl;

		// Handgun validation

		valid = false;
		if (gunKey == "h") {
			hgFunction gunFunc;

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Semi Automatic = sm, automatic = a)";
					cin >> function; cout << endl;
					if (function != "sm" && function != "a")
						throw invalidKeyException("Invalid key! Valid keys are: sm, a");
					else {
						valid = true;
						gunFunc = convertToHg(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Handgun(bulletCapacity, weight, name, gunFunc);
			shop.editItem<Handgun>(ind - 1, newGun);
		}

		// Revolver validation

		if (gunKey == "rv") {
			rvFunction gunFunc = rvFunction();

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Single Action = s, Double Action = d)";
					cin >> function; cout << endl;
					if (function != "s" && function != "d")
						throw invalidKeyException("Invalid key! Valid keys are: s, d");
					else {
						valid = true;
						gunFunc = convertToRv(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Revolver(bulletCapacity, weight, name, gunFunc);
			shop.editItem<Revolver>(ind - 1, newGun);
		}

		// Rifle validation

		if (gunKey == "rf") {
			rfFunction gunFunc = rfFunction();
			
			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Lever Action = l, Bolt Action = b, Semi Automatic = s)";
					cin >> function; cout << endl;
					if (function != "l" && function != "b" && function != "s")
						throw invalidKeyException("Invalid key! Valid keys are: l, b, s");
					else {
						valid = true;
						gunFunc = convertToRf(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Rifle(bulletCapacity, weight, name, gunFunc);
			shop.editItem<Rifle>(ind - 1, newGun);
		}

		// Shotgun validation

		if (gunKey == "sg") {
			sgFunction gunFunc = sgFunction();

			while (!valid) {
				try {
					string function;
					cout << setw(5) << "Function (Break Action = b, Lever Action = l, Pump Action = p, Semi Automatic = s)";
					cin >> function; cout << endl;
					if (function != "b" && function != "l" && function != "p" && function != "s")
						throw invalidKeyException("Invalid key! Valid keys are: b, l, p, s");
					else {
						valid = true;
						gunFunc = convertToSg(function);
					}
				}
				catch (invalidKeyException& e) {
					cout << e.what() << '\n';
				}
			}
			Gun* newGun = new Shotgun(bulletCapacity, weight, name, gunFunc);
			shop.editItem<Shotgun>(ind - 1, newGun);
		}

		cout << setw(5) << "Gun succesfully added!" << endl;
		return true;
	}

	if (key == "U" || key == "u") {
		shop.undo();
	}

	if (key == "RE" || key == "re") {
		shop.redo();
	}

	if (key == "S" || key == "s") {
		this->displayAll();
	}

	if (key == "Q" || key == "q") {
		this->running = false;
	}

	return false;
}

void UI::displayHeader()
{
	cout << right << setw(10) << "Number |";
	cout << right << setw(20) << "Type |";
	cout << right << setw(20) << "Name |";
	cout << right << setw(20) << "Bullet Capacity |";
	cout << right << setw(20) << "Weight |";
	cout << right << setw(20) << "Function |";
	cout << endl;
	char prev = cout.fill();
	cout << setw(110) << setfill('-') << "" << endl;
	cout.fill(prev);
}

void UI::displayAll()
{
	this->displayHeader();
	for (int i = 0; i < shop.getStorage().getSize(); i++) {
		cout << setw(8) << i + 1 << " |";
		shop.getStorage().getAll()[i]->display();
	}
}

void UI::displayMenu()
{
	char prev = cout.fill();
	cout << setw(32) << setfill('-') << "" << endl;
	cout.fill(prev);
	cout << "|" << left << setw(30) << " Menu" << "|" << endl;
	cout << setw(32) << setfill('-') << "" << endl;
	cout.fill(prev);
	cout << "|" << setw(30) << "  Add Gun (A/a)" << "|" << endl;
	cout << "|" << setw(30) << "  Remove Gun (R/r)" << "|" << endl;
	cout << "|" << setw(30) << "  Modify Gun (M/m)" << "|" << endl;
	cout << "|" << setw(30) << "  Show all guns (S/s)" << "|" << endl;
	cout << "|" << setw(30) << "  Undo (U/u)" << "|" << endl;
	cout << "|" << setw(30) << "  Redo (RE/re)" << "|" << endl;
	cout << "|" << setw(30) << "  Quit (Q/q)" << "|" << endl;
	cout << setw(32) << setfill('-') << "" << endl;
	cout.fill(prev);

	string key;
	cout << setw(5) << "Waiting for input..." << endl;
	cin >> key; cout << endl;

	bool done = doOperation(key);
	
}

void UI::display()
{
	shop.loadCsv("C:/Users/seNNNz0rel/Documents/Lab Sem II/GunShop/GunShop/example.csv");

	cout << setw(20) << "Welcome to my Gun Shop!" << '\n';

	while (running) {
  			displayMenu();
	}

	shop.saveCsv("C:/Users/seNNNz0rel/Documents/Lab Sem II/GunShop/GunShop/example.csv");
}
