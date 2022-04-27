#include "FilteringTest.h"

void FilteringTest::runAllTests()
{
	creationTest();
	filteringTest();
}
int FilteringTest::creationTest() {
  // filter by price object creation
  	FilterByPrice filterPrice1 = FilterByPrice();
	FilterByPrice filterPrice2 = FilterByPrice(3);

	assert(filterPrice1.getPrice() == 0);
	assert(filterPrice2.getPrice() == 3);

	// filter by type object creation
	FilterByType filterType1 = FilterByType();
	FilterByType filterType2 = FilterByType(allInclusive);

	assert(filterType1.getType() == cruise);
	assert(filterType2.getType() == allInclusive);

	// filter by type and price object creation
	FilterCriteriaAnd<FilterByPrice, FilterByType> filterByTypeAndPrice1 = FilterCriteriaAnd<FilterByPrice, FilterByType>();
	FilterCriteriaAnd<FilterByPrice, FilterByType> filterByTypeAndPrice2 = FilterCriteriaAnd<FilterByPrice, FilterByType>(filterPrice2, filterType2);
	
	assert(filterByTypeAndPrice1.getCrt1().getPrice() == 0);
	assert(filterByTypeAndPrice2.getCrt1().getPrice() == 3);

	assert(filterByTypeAndPrice1.getCrt2().getType() == cruise);
	assert(filterByTypeAndPrice2.getCrt2().getType() == allInclusive);

	return 0;
}

int FilteringTest::filteringTest()
{
	// Create some offers
	Offer offer1 = Offer("1", "Cluj", "Rome", 150, "20th May", "26th May", cruise);
	Offer offer2 = Offer("2", "Bucharest", "Prague", 350, "10th June", "20th June", allInclusive);
	Offer offer3 = Offer("3", "Cluj", "Bucharest", 100, "1st July", "8th July", cityBreak);
	Offer offer4 = Offer("4", "Iasi", "New York", 1000, "2nd August", "20th August", allInclusive);

	// Create expected result after filtering
	DynamicArray<Offer> filterResult1 = DynamicArray<Offer>(), filterResult2 = DynamicArray<Offer>(), filterResult3 = DynamicArray<Offer>();
	filterResult1.append(offer1);
	filterResult1.append(offer2);
	filterResult1.append(offer3);

	filterResult2.append(offer2);
	filterResult2.append(offer4);

	filterResult3.append(offer2);


	// Create dynamic array of offers
	DynamicArray<Offer> offers1 = DynamicArray<Offer>();
	offers1.append(offer1);
	offers1.append(offer2);
	offers1.append(offer3);
	offers1.append(offer4);
	DynamicArray<Offer> offers2 = offers1, offers3 = offers1;


	// Create filters and check if it has the expected result
	FilterByPrice filter1 = FilterByPrice(400);
	filter1.filter(offers1);

	assert(offers1.getLength() == filterResult1.getLength());

	for (int i = 0; i < offers1.getLength(); i++)
		assert(offers1.get(i) == filterResult1.get(i));

	FilterByType filter2 = FilterByType(allInclusive);
	filter2.filter(offers2);

	assert(offers2.getLength() == filterResult2.getLength());

	for (int i = 0; i < offers2.getLength(); i++)
		assert(offers2.get(i) == filterResult2.get(i));

	FilteringCriteria* filter3 = new FilterCriteriaAnd<FilterByPrice, FilterByType>(filter1, filter2);
	filter3->filter(offers3);

	assert(offers3.getLength() == filterResult3.getLength());

	for (int i = 0; i < offers3.getLength(); i++)
		assert(offers3.get(i) == filterResult3.get(i));

	return 0;
}
