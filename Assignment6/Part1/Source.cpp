#include<iostream>
#include<ctime>
using namespace std;
#include"STACKLLIST.h"

	//resetting the linked list to display the even numbers first
void evenB4Odd(stack_llist<int>& ALL) {
		//create two new objects
	stack_llist<int> EVEN, ODD;
		//intialize the objects depending if they are even or odd
	while(!ALL.empty_s()) {
		int t = ALL.pop_s();
		if (t % 2 == 0)
			EVEN.insert(t);
		else
			ODD.insert(t);
	}
		//re-arrange the linked list ALL
	for(int i = 0; i <10; ++i){
		if (!ODD.empty_s()) 
			ALL.insert(ODD.pop_s());
		else
			ALL.insert(EVEN.pop_s());
	}
}

int main() {

	srand(time(0));
		//create an object of the linked list class
	stack_llist<int> ALL;
		//insert 10 random numbers between 10 - 40
	for (int i = 0; i < 10; ++i) {
		ALL.insert(rand()%30+10);
	}

		//display the original list and the new list
	cout << "ORIGINAL ALL: \t";
	ALL.display();
	evenB4Odd(ALL);
	cout << "NEW ALL: \t";
	ALL.display();

	system("pause");
	return 0;
}
/****************************************************

ORIGINAL ALL:   14->26->39->25->38->16->23->26->33->28->NULL
NEW ALL:        14->26->38->16->26->28->39->25->23->33->NULL
Press any key to continue . . .

****************************************************/