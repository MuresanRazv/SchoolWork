#include "OfferTest.h"

void OfferTest::runAllTests()
{
	creationTest();
	equalTest();
	gettersTest();
}

int OfferTest::equalTest() {
	Offer offer1 = Offer(), offer2 = Offer();
	Offer offer3 = Offer("1", "Cluj", "Rome", 150, "20th May", "26th May", cruise);
	Offer offer4 = Offer("2", "Bucharest", "Prague", 350, "10th June", "20th June", allInclusive);

	assert(offer1.operator==(offer2));
	assert(!(offer3.operator==(offer4)));

	return 0;
}

int OfferTest::creationTest() {
	Offer offer1 = Offer();

	assert(offer1.getPrice() == 0);
	assert(offer1.getType() == circuit);
	
	return 0;
}

int OfferTest::gettersTest() {
	Offer offer1 = Offer("1", "Cluj", "Rome", 150, "20th May", "26th May", cruise);
	Offer offer2 = Offer("2", "Bucharest", "Prague", 350, "10th June", "20th June", allInclusive);

	assert(offer1.getPrice() == 150);
	assert(offer2.getPrice() == 350);

	assert(offer1.getType() == cruise);
	assert(offer2.getType() == allInclusive);

	return 0;
}

