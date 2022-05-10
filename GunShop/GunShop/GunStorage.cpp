#include "GunStorage.h"

GunStorage::GunStorage()
{
}

GunStorage::GunStorage(const GunStorage& other)
{
	this->guns = other.guns;
}

GunStorage::~GunStorage()
{
	guns.clear();
}

int GunStorage::getSize()
{
	return guns.size();
}

vector<Gun*> GunStorage::getAll()
{
	return guns;
}

void GunStorage::setStorage(vector<Gun*> newStorage)
{
	guns = newStorage;
}

void GunStorage::displayAll()
{
	for (int i = 0; i < guns.size(); i++) {
		guns[i]->display();
	}
}

void GunStorage::addItem(Gun& newGun)
{
	guns.push_back(&newGun);
}

void GunStorage::insertItem(Gun& newGun, int ind)
{
	guns.insert(guns.begin() + ind, &newGun);
}

void GunStorage::removeItem(int ind)
{
	guns.erase(guns.begin() + ind);
}

std::vector<string> GunStorage::tokenize(string str, char delimiter)
{

	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

string GunStorage::getTypeInString(int ind)
{
	Handgun* hg = dynamic_cast<Handgun*>(guns[ind]);
	if (hg != nullptr)
		return "Handgun";
	
	Revolver* rv = dynamic_cast<Revolver*>(guns[ind]);
	if (rv != nullptr)
		return "Revolver";
	
	Rifle* rf = dynamic_cast<Rifle*>(guns[ind]);
	if (rf != nullptr)
		return "Rifle";
	
	Shotgun* sg = dynamic_cast<Shotgun*>(guns[ind]);
	if (sg != nullptr)
		return "Shotgun";
}

string GunStorage::getFunctionInString(int ind)
{
	Handgun* hg = dynamic_cast<Handgun*>(guns[ind]);
	if (hg != nullptr) {
		if (hg->getFunc() == automaticHg)
			return "Automatic";
		if (hg->getFunc() == semiAutomaticHg)
			return "Semi Automatic";
	}

	Revolver* rv = dynamic_cast<Revolver*>(guns[ind]);
	if (rv != nullptr) {
		if (rv->getFunc() == singleAction)
			return "Single Action";
		if (rv->getFunc() == doubleAction)
			return "Double Action";
	}

	Rifle* rf = dynamic_cast<Rifle*>(guns[ind]);
	if (rf != nullptr) {
		if (rf->getFunc() == leverActionRf)
			return "Lever Action";
		if (rf->getFunc() == boltAction)
			return "Bolt Action";
		if (rf->getFunc() == semiAutomaticRf)
			return "Semi Automatic";
	}

	Shotgun* sg = dynamic_cast<Shotgun*>(guns[ind]);
	if (sg != nullptr) {
		if (sg->getFunc() == breakAction)
			return "Break Action";
		if (sg->getFunc() == leverActionSg)
			return "Lever Action";
		if (sg->getFunc() == pumpAction)
			return "Pump Action";
		if (sg->getFunc() == semiAutomatic)
			return "Semi Automatic";
	}
}

bool GunStorage::loadFromCsv(string csvPath)
{
	ifstream csv(csvPath);

	if (!csv.is_open())
		return false;

	while (!csv.eof()) {
		string line;
		getline(csv, line);

		vector<string> tokens = tokenize(line, ',');
		if (tokens.size() == 5) {


			string name = tokens[1];

			int bulletCapacity = 0;
			std::istringstream(tokens[2]) >> bulletCapacity;

			int weight = 0;
			std::istringstream(tokens[3]) >> weight;

			// Handgun
			
			if (tokens[0] == "Handgun")
			{
				hgFunction gunFunc = hgFunction();
				if (tokens[4] == "Semi Automatic")
					gunFunc = semiAutomaticHg;
				else if (tokens[4] == "Automatic")
					gunFunc = automaticHg;

				Gun* newGun = new Handgun(bulletCapacity, weight, name, gunFunc);
				this->addItem(*newGun);
			}

			// Revolver
			
			if (tokens[0] == "Revolver")
			{
				rvFunction gunFunc = rvFunction();
				if (tokens[4] == "Single Action")
					gunFunc = singleAction;
				else if (tokens[4] == "Double Action")
					gunFunc = doubleAction;

				Gun* newGun = new Revolver(bulletCapacity, weight, name, gunFunc);
				this->addItem(*newGun);
			}

			// Rifle


			if (tokens[0] == "Rifle")
			{
				rfFunction gunFunc = rfFunction();
				if (tokens[4] == "Lever Action")
					gunFunc = leverActionRf;
				else if (tokens[4] == "Bolt Action")
					gunFunc = boltAction;
				else if (tokens[4] == "Semi Automatic")
					gunFunc = semiAutomaticRf;

				Gun* newGun = new Rifle(bulletCapacity, weight, name, gunFunc);
				this->addItem(*newGun);
			}

			// Shotgun

			if (tokens[0] == "Rifle")
			{
				sgFunction gunFunc = sgFunction();
				if (tokens[4] == "Break Action")
					gunFunc = breakAction;
				else if (tokens[4] == "Lever Action")
					gunFunc = leverActionSg;
				else if (tokens[4] == "Pump Action")
					gunFunc = pumpAction;
				else if (tokens[4] == "Semi Automatic")
					gunFunc = semiAutomatic;

				Gun* newGun = new Shotgun(bulletCapacity, weight, name, gunFunc);
				this->addItem(*newGun);
			}

		}

	}

	csv.close();

	return true;
}

bool GunStorage::saveCsv(string csvPath)
{
	ofstream csv(csvPath);

	if (!csv.is_open())
		return false;

	for (int i = 0; i < guns.size(); i++) {
		csv << this->getTypeInString(i) << "," << this->getAll()[i]->getName() << ","
			<< this->getAll()[i]->getBulletCapacity() << "," << this->getAll()[i]->getWeight() << ","
			<< this->getFunctionInString(i) << endl;
		delete guns[i];
	}
	
	csv.close();

	return true;
}
