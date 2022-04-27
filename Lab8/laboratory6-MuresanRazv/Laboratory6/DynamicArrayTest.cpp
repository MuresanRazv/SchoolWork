#include "DynamicArrayTest.h"

void DynamicArrayTest::runAllTests()
{
	creationTest();
	appendTest();
	popBackTest();
	removeTest();
}

int DynamicArrayTest::creationTest() {
	DynamicArray<Offer> arr1 = DynamicArray<Offer>();

	assert(arr1.getLength() == 0);
	assert(arr1.getCapacity() == 100);

	DynamicArray<Offer> arr2 = DynamicArray<Offer>(50);
	arr2.append(Offer());

	assert(arr2.getLength() == 1);
	assert(arr2.getCapacity() == 50);

	return 0;
}

int DynamicArrayTest::appendTest() {
	DynamicArray<Offer> arr1 = DynamicArray<Offer>();

	assert(arr1.getLength() == 0);

	arr1.append(Offer());
	assert(arr1.getLength() == 1);
	assert(arr1.get(0) == Offer());

	return 0;
}

int DynamicArrayTest::popBackTest() {
	DynamicArray<Offer> arr1 = DynamicArray<Offer>();
	
	arr1.append(Offer());
	arr1.append(Offer());

	assert(arr1.getLength() == 2);
	assert(arr1.popBack() == Offer());
	assert(arr1.getLength() == 1);

	return 0;
}

int DynamicArrayTest::removeTest() {
	DynamicArray<Offer> arr1 = DynamicArray<Offer>();

	Offer offer1 = Offer("1", "Cluj", "Rome", 150, "20th May", "26th May", cruise);
	Offer offer2 = Offer("2", "Bucharest", "Prague", 350, "10th June", "20th June", allInclusive);

	arr1.append(offer1);
	arr1.append(offer2);

	assert(arr1.getLength() == 2);
	assert(arr1.get(0) == offer1);

	arr1.remove(0);
	assert(arr1.getLength() == 1);
	assert(arr1.get(0) == offer2);

	return 0;
}
