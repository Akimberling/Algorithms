/*********************************************
Name:	 Amber Kimberling & Tianna Cano
Assignment: 	Assignment No6 Pt 4
Course:		CMPS 400

Purpose: insert up to 10 elements into two sets
in an ordered list.
Display both sets and their intersection set.
*********************************************/
#include<iostream>
using namespace std;
#include"ORDERLLIST.h"

void intersection()
{

}

int main()
{
	int n = 0, x = 0, y = 0, z = 0;
	//create an object of the linked list class
	order_llist<int> setA;
	order_llist<int> setB;
	order_llist<int> setAIB;
	//insert up to 10 elements in the set
	cout << "Enter up to 10 elements into a setA: ";
	while (x != -1)
	{
		cin >> x;
		setA.insert(x);
		if (x == -1)
			setA.pop_s();
		n++;
	}

	cout << "Enter up to 10 elements into a setB: ";
	while (y != -1)
	{
		cin >> y;
		setB.insert(y);
		if (y == -1)
			setB.pop_s();
		z++;
	}

	//display the original list and the new list
	cout << "setA: \t";
	setA.display();
	cout << "setB: \t";
	setB.display();

	//
	cout << "-----------------------------" << endl;
	cout << "setA U setB:\t";
	setA.unionSet(setA, setB);
	cout << endl;

	cout << "-----------------------------" << endl;
	cout << "setA intersect setB:\t";
	setA.intersectionSet(setA, setB);
	cout << endl;

	system("pause");
	return 0;
}