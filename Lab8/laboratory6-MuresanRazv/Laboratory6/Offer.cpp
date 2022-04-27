#include "Offer.h"

Offer::Offer()
{
	id = "0";
	departureLocation = "None";
	destinationLocation = "None";
	price = 0;
	startDate = "None";
	endDate = "None";
	offerType = circuit;
}

Offer::Offer(string id, string depLoc, string destLoc, int pr, string stDt, string endDt, type offerType)
{
	this->id = id;
	departureLocation = depLoc;
	destinationLocation = destLoc;
	price = pr;
	startDate = stDt;
	endDate = endDt;
	this->offerType = offerType;
}

type Offer::getType() const
{
	return this->offerType;
}

string Offer::getDeparture() const
{
	return this->departureLocation;
}

bool Offer::operator==(const Offer offer)
{
	if (departureLocation != offer.departureLocation || destinationLocation != offer.destinationLocation || 
		price != offer.price || offerType != offer.offerType || startDate != offer.startDate || endDate != offer.endDate)
		return false;

	return true;
}

int Offer::getPrice() const
{
	return this->price;
}

ostream& operator<<(ostream& s, const Offer offer) {
	s << "Departure Location: " << offer.departureLocation << '\n';
	s << "Destination Location: " << offer.destinationLocation << '\n';
	s << "Price: " << offer.price << '\n';
	s << "Start Date: " << offer.startDate << '\n';
	s << "End Date: " << offer.endDate << '\n';
	s << "Offer Type: " << offer.offerType << '\n';
	s << '\n';
	return s;
}
