// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "Tree.h"
#include "stdafx.h"

int main()
{
	Tree tr;

	int numb; 
	printf("Enter the number: ");
	std::cin >> numb; 
	tr.Add(numb);

	while (numb != -1)
	{
		system("cls");
		tr.Show();

		printf("Enter the number: ");
		std::cin >> numb;
		tr.Add(numb);
	}

	system("pause");
	return 0;
}
