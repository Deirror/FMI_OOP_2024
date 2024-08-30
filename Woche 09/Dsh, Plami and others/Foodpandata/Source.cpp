#include <iostream>
#include "Foodpanda.h"

int main()
{
	Foodpanda fp;

	List products;
	products.push_back("Sirene");
	products.push_back("Kashkawal");
	products.push_back("Meso");
	products.push_back("Kroasan");

	Restaurant rest1("Idar", products);
	
	fp.addRestaurant(rest1);

	products.erase(1);

	Order order("Idar",products);

	fp.addOrderToRestaurant(order);

	//
	products.pop_back();

	List productsDirh;
	productsDirh.insert("Bob",0);
	productsDirh.insert("PrincipNaDirihle", 1);

	Restaurant restaurants[2] = { {"Deirro", products}, {"Dirihle",productsDirh} };

	Foodpanda fp2(restaurants, 2);

	fp2.addProductToRestaurant("QuickMath", "Deirro");
	fp2.addRestaurant(rest1);

	return 0;
}