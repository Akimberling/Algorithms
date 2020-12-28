
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#include "BSTREE.h"

int main()
{
		//declare and initialize variables
	BTREE t;
	string monthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		//insert the array into the tree
	for (int z = 0; z < 12; ++z)
	{
		t.insert(monthName[z]);
	}
		//display the tree inorder traversal
	cout << "\nInOrder Traversal: ";
	t.displayInOrder();
		//display the height of the tree
	cout << "\nHeight of the tree: " << t.treeHeight() <<endl;
		//display the ancestors
	cout << "\nThe ancestors of Dec: "<<endl;
	t.showAncestor("Dec");
		//remove the leaves of the tree
	t.remLeaves();
		//display the tree sideways
	cout << "\n\nTree Sideways: " << endl;
	int count = 0;
	t.sideWay(count);
		//count the number of nodes
	cout << "\n\nNumber of nodes: " << t.countNodes();
	cout << endl;

	system("pause");
	return 0;
}

/******************************OUTPUT******************************

InOrder Traversal: Apr Aug Dec Feb Jan Jul Jun Mar May Nov Oct Sep
Height of the tree: 5

The ancestors of Dec:
Aug Apr Feb Jan

Tree Sideways:
				 Sep
					  Oct
			May
	   Mar
			Jun
  Jan
	   Feb
				 Aug
			Apr


Number of nodes: 9
Press any key to continue . . .

******************************************************************/