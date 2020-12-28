/***************************************
Amber Kimberling 
CMPS 400
Assignment No 8 Pt b

using Breadth First Seaerch to traverse 
the graph
**some code used from notes**
***************************************/
#ifndef BFS
#define BFS
	//breadth first search traversal class
class cBfsTraversal
{
private:
		//queue stack
	queue <int> QUE;
		//declaration and initialization of variables
	int vertStatus[MAX], graphMatrix[MAX][MAX], numVert;
public:
	cBfsTraversal() {}
		//data retrieval of the graph
	void getData()
	{
			//prompt user to enter the number of verticies
		cout << "\nPlease enter the total number of vertices: ";
		cin >> numVert;

			//declaration and initialization of variables
		int source, destination, maxEdge = numVert * (numVert - 1) / 2;

			//loop to enter all the edges in the graph
		for (int z = 1; z <= maxEdge; z++)
		{
			cout << "\nPlease Enter the source and destination of vertex "
				<< z << " and 0 for both to Exit:\nsource: ";
			cin >> source;
			cout << "desination: ";
			cin>> destination;

				//if user entered 0 twice exit else set the matrix coordinates to 1
			if (destination == 0 && source ==  0)
			{
				break;
			}
			else
			{
				graphMatrix[source][destination] = 1;
				graphMatrix[destination][source] = 1;
			}
		}
	}
		//traverse the graph
	void bfsTraversal()
	{
			//loop through and set the status of all vertices to unvisited
		for (int z = 1; z <= numVert; z++)
		{
			vertStatus[z] = unvisited;
		}
			//declaration of variable
		int source;

			//prompt  user to enter the point at which they want to begin traversing the graph
		cout << "\nPlease enter the source from where you wish to start traversing: \n";
		cin >> source;
		
			//display the traversal of the graph
		cout << "\nTraversal Order: ";
		cout << source;

			//set the status at the source to visited
		vertStatus[source] = visited;
		QUE.push(source);

			//while the stack is not empty
		while (!QUE.empty())
		{
				//set the source to the front of the stack
			source = QUE.front();
				//pop the stack
			QUE.pop();
				//loop through displaying each vertex
			for (int z = 1; z <= numVert; z++)
			{
					//if the status is unvisited and graph matrix is 1
				if (vertStatus[z] == unvisited && graphMatrix[source][z] == 1)
				{
						//display the vertex and set its status to visited
					cout << "-->" << z;
					vertStatus[z] = visited;
					QUE.push(z);
				}
			}
		}
	}

};


#endif