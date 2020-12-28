/****************************************************************************
Amber Kimberling
Using dynamic programming to solve the 0/1 Knapsack problem
****************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

	//returns the max Value 
int max(int valA, int ValB)
{
		//if (A > B) ? return A else return B
	return (valA > ValB) ? valA : ValB;
}

	//returns the Max value found in the Knapsack
int knapSack(int capOfKnap, int weight[], int value[], int numOfItem)
{
		//declare variables and dynamic multidemensional array setting its row# size
	int items, weights;
	int** knapS = new int*[numOfItem+1];

		//Set the num of columna in each row of the dynamic multidemensional array
	for (int i = 0; i < numOfItem+1; ++i)
		knapS[i] = new int[capOfKnap+1];

		//build the tbale of the Knapsack to find the max val by items and weights
	for (items = 0; items <= numOfItem; items++)
	{
		for (weights = 0; weights <= capOfKnap; weights++)
		{
			//if both are 0 return 0
			if (items == 0 || weights == 0) {
				knapS[items][weights] = 0;
			}
			//if the weight before  is <= weights then set the max value
			else if (weight[items - 1] <= weights){
				knapS[items][weights] = max(value[items - 1] + knapS[items - 1][weights - weight[items - 1]], knapS[items - 1][weights]);
			}
				//else set the KnapS to the previos item and the weight
			else {
				knapS[items][weights] = knapS[items - 1][weights];
			}
		}
	}

	cout << endl;
		//display the table
	for (int i = 0; i <= numOfItem; ++i)
	{
		for (int w = 0; w <= capOfKnap; w++)
			cout << setw(5) << knapS[i][w];
		cout << endl;
	}
		//return the maxValue
	return knapS[numOfItem][capOfKnap];
}

int main()
{
		//declare and initialize variables
	int numOfItems, capOfKnap, *value = NULL, *weight = NULL, maxVal;

		//prompt user to enter the items(this will be the size of the arrays) and capacity
	cout << "Enter the number of Items and Capacity of the Knapsack: ";
	cin >> numOfItems >> capOfKnap;

		//declare the dynamic array with a size of numOfItems(entered by user)
	value = new int[numOfItems];
	weight = new int[numOfItems];

		//promp user to enter the value and weight of each item 
	cout << "\n\tEnter the values and weights for each item:" << endl;

		//use a for loop to visit each index of the array to store the values entered by user
	for (int i = 0; i < numOfItems; ++i) {
		cout << "\t\tItem " << i+1 << " value and weight: ";
		cin >> value[i] >> weight[i];
	}

		//call the return function Knapsack to get the returned MAX
	maxVal = knapSack(capOfKnap, weight, value, numOfItems);

		//display the max value found in the sack
	cout << "\nMaximum value in the knapsack = " << maxVal << endl;

	system("PAUSE");
	return 0;
}
/************************************************************************************

Enter the number of Items and Capacity of the Knapsack: 5 15

		Enter the values and weights for each item:
				Item 1 value and weight: 7 3
				Item 2 value and weight: 9 4
				Item 3 value and weight: 5 2
				Item 4 value and weight: 12 6
				Item 5 value and weight: 14 7

	0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
	0    0    0    7    7    7    7    7    7    7    7    7    7    7    7    7
	0    0    0    7    9    9    9   16   16   16   16   16   16   16   16   16
	0    0    5    7    9   12   14   16   16   21   21   21   21   21   21   21
	0    0    5    7    9   12   14   16   17   21   21   24   26   28   28   33
	0    0    5    7    9   12   14   16   17   21   21   24   26   28   30   33

Maximum value in the knapsack = 33
Press any key to continue . . .

************************************************************************************/
