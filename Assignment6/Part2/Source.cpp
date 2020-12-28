#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;
#include"QUELLIST.h"

	//check whether the scentence is a Palindrome
bool isPalindrom(que_llist<char> ORIGINALLIST, que_llist<char> LISTREV) {

		//while the reversed list is not empty
	while (!LISTREV.empty_s()) {
			//declare and initialize temporary variables to letters in list
		char T1 = ORIGINALLIST.pop_s();
		char T2 = LISTREV.pop_s();
			//if they are not equal return false
		if (T1 != T2) {
			return false;
		}
	}
		//if the Original list is not empty then pop list one more time
	if(!ORIGINALLIST.empty_s())
		ORIGINALLIST.pop_s();

		//if both lists are empty return true else return false
	if (LISTREV.empty_s() && ORIGINALLIST.empty_s())
		return true;
	else
		return false;
}

int main() {

		//declare variables
	char cLetter, yesNo;

	do {
			//create objects of the quelist
		que_llist<char> ORIGINALLIST, LISTREV, TEMPLIST;
			//prompt user to enter a scentence
		cout << "Enter a scentece to test whether it is a Palindrom: ";
			//while you are reading character by character
		while (cin.get(cLetter), cLetter != '\n') {
				//if it is a number or a letter 
			if (isalnum(cLetter)) {
					//insert characters into 2 lists
				ORIGINALLIST.insert(tolower(cLetter));
				TEMPLIST.insert(tolower(cLetter));
			}
		}

			//display the original list
		cout << "Original List: ";
		ORIGINALLIST.display();
			//find the middle node and displat
		cLetter = ORIGINALLIST.findMiddleNode();
		cout << "Middle Node: " << cLetter << endl;
			//delete the original list
		ORIGINALLIST.deleteList();
			//while the temp list is not empty
		while (!TEMPLIST.empty_s()) {
				//pop items from the list
			char cTemp = TEMPLIST.pop_s();
				//insert into the original list
			ORIGINALLIST.insert(cTemp);
				//if the letter is equal to the middle node
			if (cTemp == cLetter) {
					//continue until temp list is empty
				while (!TEMPLIST.empty_s()) {
						//insert into the reversed list
					LISTREV.reverse(TEMPLIST.pop_s());
				}
			}
		}
			//display the content of the lists
		cout << endl<<"Original beginning: ";
		ORIGINALLIST.display();
		cout << "Original End Reversed: ";
		LISTREV.display();
		cout << endl;

			//if it is a palindrome prompt the user if not prompt user
		if (isPalindrom(ORIGINALLIST, LISTREV))
			cout << "This scentence is a Palindrome." << endl;
		else
			cout << "This scentence is not a Palindrome." << endl;

			//prompt user if they would like to continue
		cout << "Would you like to continue? y or n: ";
		cin >> yesNo;
		yesNo = tolower(yesNo);

		cin.ignore();
		cout << endl;

	} while (yesNo == 'y');

	system("pause");
	return 0;
}
/**********************************************************

Enter a scentece to test whether it is a Palindrom: a Toyota
Original List: a->t->o->y->o->t->a->NULL
Middle Node: y

Original beginning: a->t->o->y->NULL
Original End Reversed: a->t->o->NULL

This scentence is a Palindrome.
Would you like to continue? y or n: y

Enter a scentece to test whether it is a Palindrom: No 2332 on
Original List: n->o->2->3->3->2->o->n->NULL
Middle Node: 3

Original beginning: n->o->2->3->NULL
Original End Reversed: n->o->2->3->NULL

This scentence is a Palindrome.
Would you like to continue? y or n: y

Enter a scentece to test whether it is a Palindrom: redCoat
Original List: r->e->d->c->o->a->t->NULL
Middle Node: c

Original beginning: r->e->d->c->NULL
Original End Reversed: t->a->o->NULL

This scentence is not a Palindrome.
Would you like to continue? y or n: n

Press any key to continue . . .

**********************************************************/