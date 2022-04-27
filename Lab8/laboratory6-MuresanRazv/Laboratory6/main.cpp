#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include "FilteringCriteria.h"
#include "MyEmptyArrayException.h"
#include "MyOutOfBoundsException.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "DynamicArray.h"

void displayMenu(DynamicArray<Offer> offerList) {
	bool running = true;
	while (running) {
		cout << "Please select your option: \n";
		cout << setw(5);
		cout << "A|a add an offer\n";

		cout << setw(5);
		cout << "S|s show all offers\n";

		cout << setw(5);
		cout << "P|p filter offers by price\n";

		cout << setw(5);
		cout << "T|t filter offers by type\n";

		cout << setw(5);
		cout << "B|b filter offers by price and type\n";

		cout << setw(5);
		cout << "Q|q quit\n";

		string key;
		cin >> key;

		if (key == "A" || key == "a") {
			string id;
			string depLoc;
			string destLoc;
			int pr;
			string stDt;
			string endDt;
			int offerType;

			cout << "Please input the following required fields: \n";

			cout << setw(5);
			cout << "ID: \n"; cin >> id;

			cout << setw(5);
			cout << "Departure Location: \n"; cin >> depLoc;

			cout << setw(5);
			cout << "Destination Location: \n"; cin >> destLoc;

			cout << setw(5);
			cout << "Price: \n"; cin >> pr;

			cout << setw(5);
			cout << "Start Date: \n"; cin >> stDt;

			cout << setw(5);
			cout << "End Date: \n"; cin >> endDt;

			cout << setw(5);
			cout << "Offer Type: (circuit = 0, cityBreak = 1, cruise = 2, allInclusive = 3)\n"; cin >> offerType;
			if (offerType == 0)
				offerList.append(Offer(id, depLoc, destLoc, pr, stDt, endDt, circuit));
			if (offerType == 1)
				offerList.append(Offer(id, depLoc, destLoc, pr, stDt, endDt, cityBreak));
			if (offerType == 2)
				offerList.append(Offer(id, depLoc, destLoc, pr, stDt, endDt, cruise));
			if (offerType == 3)
				offerList.append(Offer(id, depLoc, destLoc, pr, stDt, endDt, allInclusive));
		}
		
		if (key == "S" || key == "s") {
			cout << offerList;
		}

		if (key == "P" || key == "p") {
			int pr;

			cout << setw(5);
			cout << "Please enter filter price: \n"; cin >> pr;

			FilteringCriteria* f = new FilterByPrice(pr);
			f->filter(offerList);
			delete f;
		}

		if (key == "T" || key == "t") {
			int typeFilter;

			cout << setw(5);
			cout << "Please enter filter type: (circuit = 0, cityBreak = 1, cruise = 2, allInclusive = 3)\n"; cin >> typeFilter;

			if (typeFilter == 0) {
				FilteringCriteria* f = new FilterByType(circuit);
				f->filter(offerList);
				delete f;
			}
			if (typeFilter == 1) {
				FilteringCriteria* f = new FilterByType(cityBreak);
				f->filter(offerList);
				delete f;
			}
			if (typeFilter == 2) {
				FilteringCriteria* f = new FilterByType(cruise);
				f->filter(offerList);
				delete f;
			}
			if (typeFilter == 3) {
				FilteringCriteria* f = new FilterByType(allInclusive);
				f->filter(offerList);
				delete f;
			}
		}

		if (key == "B" || key == "b") {
			int pr, typeFilter;

			cout << setw(5);
			cout << "Please enter filter price: \n"; cin >> pr;

			cout << setw(5);
			cout << "Please enter filter type: (circuit = 0, cityBreak = 1, cruise = 2, allInclusive = 3)\n"; cin >> typeFilter;

			if (typeFilter == 0) {
				FilteringCriteria* f = new FilterCriteriaAnd<FilterByPrice, FilterByType>(FilterByPrice(pr), FilterByType(circuit));
				f->filter(offerList);
				delete f;
			}
			if (typeFilter == 1) {
				FilteringCriteria* f = new FilterCriteriaAnd<FilterByPrice, FilterByType>(FilterByPrice(pr), FilterByType(cityBreak));
				f->filter(offerList);
				delete f;
			}
			if (typeFilter == 2) {
				FilteringCriteria* f = new FilterCriteriaAnd<FilterByPrice, FilterByType>(FilterByPrice(pr), FilterByType(cruise));
				f->filter(offerList);
				delete f;
			}
			if (typeFilter == 3) {
				FilteringCriteria* f = new FilterCriteriaAnd<FilterByPrice, FilterByType>(FilterByPrice(pr), FilterByType(allInclusive));
				f->filter(offerList);
				delete f;
			}
		}

		if (key == "Q" || key == "q") {
			running = false;
		}
	}
}

int main() {

	//OfferTest::runAllTests();
	//FilteringTest::runAllTests();
	//DynamicArrayTest::runAllTests();

	Offer offer1 = Offer("1", "Cluj", "Rome", 150, "20th May", "26th May", cruise);
	Offer offer2 = Offer("2", "Bucharest", "Prague", 350, "10th June", "20th June", allInclusive);
	Offer offer3 = Offer("3", "Cluj", "Bucharest", 100, "1st July", "8th July", cityBreak);
	Offer offer4 = Offer("4", "Iasi", "New York", 1000, "2nd August", "20th August", allInclusive);

	DynamicArray<Offer> offerList = DynamicArray<Offer>();
	try
	{
		offerList.get(1);
	}
	catch (MyOutOfBoundsException& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		offerList.popBack();
	}
	catch (MyEmptyArrayException& e)
	{
		std::cout << e.what() << '\n';
	}
	
	
	offerList.append(offer1);
	offerList.append(offer2);
	offerList.append(offer3);
	offerList.append(offer4);

	try {
		offerList.remove(5);
	}
	catch (MyOutOfBoundsException& e) {
		std::cout << e.what() << '\n';
	}

	//cout << offerList;

	FilteringCriteria* f = new FilterCriteriaAnd<FilteringCriteriaDeparture, FilterByType>(FilteringCriteriaDeparture("Cluj"), FilterByType(cruise));
	f->filter(offerList);
	delete f;

	//cout << offerList;

	//displayMenu(offerList);

	return 0;
}