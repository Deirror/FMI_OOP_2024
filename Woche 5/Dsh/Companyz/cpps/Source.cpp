#include <iostream>
#include "Company.h"

int main()
{
	Company cmp;

	cmp.addDepartment("Sagapao");

	cmp.addDepartment("Harwai");

	Employee emp1(1,"Dara Ekimova","Singer", 10000);

	Employee emp2(2, "Iskrata", "Singer", 4444);

	cmp.addEmployeeToDepartment("Sagapao", emp1);
	cmp.addEmployeeToDepartment("Sagapao", emp2);

	cmp.removeDepartment("Harwai");

	cmp.removeEmployeeFromDepartment("Sagapao", 1);

	return 0;
}