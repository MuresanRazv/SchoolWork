#pragma once
#include "DynamicArray.h"

// you can add all your filtering classes in this module

class FilteringCriteria
{
public:
	virtual DynamicArray<Offer> filter(DynamicArray<Offer>& data) = 0;
};

class FilterByPrice : public FilteringCriteria {
public:
	FilterByPrice();
	FilterByPrice(int price);

	int getPrice();

	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	int price;
};

class FilterByType : public FilteringCriteria {
public:
	FilterByType();
	FilterByType(type newType);

	int getType();

	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	type filterType;
};

class FilteringCriteriaDeparture : public FilteringCriteria {
public:
	FilteringCriteriaDeparture();
	FilteringCriteriaDeparture(string departure);

	string getDeparture();

	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	string departure;
};

template <typename Criteria1, typename Criteria2>
class FilterCriteriaAnd : public FilteringCriteria {
public:
	FilterCriteriaAnd() {
		this->crt1 = Criteria1();
		this->crt2 = Criteria2();
	}
	FilterCriteriaAnd(Criteria1 crt1, Criteria2 crt2) {
		this->crt1 = crt1;
		this->crt2 = crt2;
	}

	Criteria1 getCrt1() {
		return this->crt1;
	}
	Criteria2 getCrt2() {
		return this->crt2;
	}

	DynamicArray<Offer> filter(DynamicArray<Offer>& data) {
		crt1.filter(data);
		crt2.filter(data);

		return data;
	}
	
private:
	Criteria1 crt1;
	Criteria2 crt2;
};

