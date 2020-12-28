#include<iostream>
#include<cstring>
using namespace std;
#include"DOUBLEYLL.h"

int main() {

	char cScentence, yesNo;

	do {

		double_llist<char> dllORIGINAL;

		cout << "Enter a scentence: ";

		while (cin.get(cScentence), cScentence != '\n') {

			if (isalnum(cScentence)) {
				dllORIGINAL.insert(tolower(cScentence));
			}
		}

		cout << "\t";
		dllORIGINAL.display();
		if (dllORIGINAL.isPalindrome())
			cout << "\tThis is a Palindrome." << endl;
		else
			cout << "\tThis is not a Palindrom." << endl;

		cout << "\t\twould you like to continue? y or n: ";
		cin >> yesNo;
		cout << endl << endl;

		cin.ignore();

	}while (yesNo == 'y');

	system("pause");
	return 0;
}
/******************************************************

Enter a scentence: a Toyota
		a-->t-->o-->y-->o-->t-->a-->NULL
		This is a Palindrome.
				would you like to continue? y or n: y


Enter a scentence: taco cat
		t-->a-->c-->o-->c-->a-->t-->NULL
		This is a Palindrome.
				would you like to continue? y or n: y


Enter a scentence: I like red Coats
		i-->l-->i-->k-->e-->r-->e-->d-->c-->o-->a-->t-->s-->NULL
		This is not a Palindrom.
				would you like to continue? y or n: n


Press any key to continue . . .

******************************************************/