#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#include "BSTREE.h"

int main()
{
	BTREE Jan2Dec, Dec2Jan;
	string monthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	for (int z = 0; z < 12; ++z)
	{
		Jan2Dec.insert(monthName[z]);
	}
	for (int z = 11; z>=0; --z)
	{
		Dec2Jan.insert(monthName[z]);
	}

	cout << "\nInOrder Traversal January to December: ";
	Jan2Dec.displayInOrder();

	cout << "\nInOrder Traversal December to January: ";
	Dec2Jan.displayInOrder();

	cout << "\n\nTree Sideways January to December: " << endl;
	int count = 0;
	Jan2Dec.sideWay(count);

	cout << "\n\nTree Sideways December to January: " << endl;
	count = 0;
	Dec2Jan.sideWay(count);

	if (Jan2Dec.sameTrees(Jan2Dec, Dec2Jan))
		cout << "\nThe trees are alike in nature" << endl;
	else
		cout << "\nThe trees are not alike.They are either structurally different or do not have the same content." << endl;
	

	system("pause");
	return 0;
}

/******************************OUTPUT******************************


InOrder Traversal January to December: Apr Aug Dec Feb Jan Jul Jun Mar May Nov Oct Sep
InOrder Traversal December to January: Apr Aug Dec Feb Jan Jul Jun Mar May Nov Oct Sep

Tree Sideways January to December:
				 Sep
					  Oct
						   Nov
			May
	   Mar
			Jun
				 Jul
  Jan
	   Feb
					  Dec
				 Aug
			Apr


Tree Sideways December to January:
				 Sep
			Oct
	   Nov
					  May
						   Mar
				 Jun
			Jul
					  Jan
				 Feb
  Dec
	   Aug
			Apr

The trees are not alike.They are either structurally different or do not have the same content.
Press any key to continue . . .

******************************************************************/