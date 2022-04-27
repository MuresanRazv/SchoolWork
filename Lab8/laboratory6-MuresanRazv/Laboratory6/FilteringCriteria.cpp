#include "FilteringCriteria.h"

DynamicArray<Offer> FilteringCriteria::filter(DynamicArray<Offer>& data)
{
	return data;
}

FilterByPrice::FilterByPrice()
{
	price = 0;
}

FilterByPrice::FilterByPrice(int price)
{
	this->price = price;
}

int FilterByPrice::getPrice()
{
	return price;
}

DynamicArray<Offer> FilterByPrice::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> filteredData;
	
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getPrice() < this->price)
			filteredData.append(data.get(i));

	data = filteredData;

	return data;
}

FilterByType::FilterByType()
{
	filterType = cruise;
}

FilterByType::FilterByType(type newType)
{
	filterType = newType;
}

int FilterByType::getType()
{
	return filterType;
}

DynamicArray<Offer> FilterByType::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> filteredData;

	for (int i = 0; i < data.getLength(); i++)
		if (this->filterType == data.get(i).getType()) 
			filteredData.append(data.get(i));
	
	data = filteredData;

	return data;
}

FilteringCriteriaDeparture::FilteringCriteriaDeparture()
{
	this->departure = "None";
}

FilteringCriteriaDeparture::FilteringCriteriaDeparture(string departure)
{
	this->departure = departure;
}

string FilteringCriteriaDeparture::getDeparture()
{
	return this->departure;
}

DynamicArray<Offer> FilteringCriteriaDeparture::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> filteredData;

	for (int i = 0; i < data.getLength(); i++)
		if (this->departure == data.get(i).getDeparture())
			filteredData.append(data.get(i));

	data = filteredData;

	return data;
}
