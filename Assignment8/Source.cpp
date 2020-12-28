#include <iostream>
#include <queue>
#define MAX 100
#define visited 2
#define unvisited 1
using namespace std;
#include "BFS.h"


int main()
{
		//create an object of the class cBfsTraversal
	cBfsTraversal G1;

		//call getData to begin the graph traversal
	cout << "----------------------------------Graph Description----------------------------------" << endl;
	G1.getData();
		//call bfsTraversal to traverse the graph
	cout << "-----------------------------------After Traversal-----------------------------------" << endl;
	G1.bfsTraversal();

	cout << endl;
	system("pause");
	return 0;
}
/*

----------------------------------Graph Description----------------------------------

Please enter the total number of vertices: 5

Please Enter the source and destination of vertex 1 and 0 for both to Exit:
source: 1
desination: 2

Please Enter the source and destination of vertex 2 and 0 for both to Exit:
source: 1
desination: 4

Please Enter the source and destination of vertex 3 and 0 for both to Exit:
source: 1
desination: 5

Please Enter the source and destination of vertex 4 and 0 for both to Exit:
source: 2
desination: 3

Please Enter the source and destination of vertex 5 and 0 for both to Exit:
source: 3
desination: 5

Please Enter the source and destination of vertex 6 and 0 for both to Exit:
source: 5
desination: 4

Please Enter the source and destination of vertex 7 and 0 for both to Exit:
source: 0
desination: 0
-----------------------------------After Traversal-----------------------------------

Please enter the source from where you wish to start traversing:
1

Traversal Order: 1-->2-->4-->5-->3
Press any key to continue . . .


*/