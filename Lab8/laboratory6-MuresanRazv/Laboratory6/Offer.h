#include <string>
#include <iostream>
using namespace std;
#pragma once

enum type {
	circuit,
	cityBreak,
	cruise,
	allInclusive
};

class Offer
{
public:
	Offer();
	Offer(string id, string depLoc, string destLoc, int pr, string stDt, string endDt, type offerType);
	
	friend ostream& operator<<(ostream& s, const Offer offer);
	bool operator==(const Offer offer);

	int getPrice() const;
	type getType() const;
	string getDeparture() const;

private:
	string id;
	string departureLocation;
	string destinationLocation;
	int price;
	string startDate;
	string endDate;
	type offerType;
};

