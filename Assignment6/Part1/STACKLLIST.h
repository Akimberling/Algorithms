/*********************************************
Amber Kimberling
AssignmentNo6Pt1
CMPS 400

insert 10 random numbers into a linked list
ALL
then change the list to display the even numbers
firstand odd last
*********************************************/
#ifndef STACKLLIST
#define STACKLLIST
	//creating a template class
template<class T>
class stack_llist
{
private:
		//declaring the nodes structure
	struct node
	{
		T info;
		node *next;
	};
		//pointing a node to the linked list of nodes
	node *stack;
public:
		//constructor
	stack_llist() { stack = NULL; }
		//check if the linked list stack is empty
	bool empty_s() { return(stack == NULL) ? true : false; }
		//inserting items into the list
	void insert(T x)
	{
			//create a new node
		node *p = new(node);
			//initialize its info and set the next valule to null
		p->info = x;
		p->next = NULL;
			//if the stack is null
		if (stack == NULL)
				//set the stack to p
			stack = p;
		else
		{
				//the next value of p is the stack
			p->next = stack;
				//set the stack to p
			stack = p;
		}
	}
		//displaying the linked list
	void display()
	{
			//create a temporary pointer to the linked list
		node* t = stack;
			//while the temp pointer is not null
		while (t != NULL)
		{
				//display its information and move to the next node
			cout << t->info << "->"; 
			t = t->next;
		}
		cout << "NULL\n";
	}
		//viewing the items one by one
	T pop_s()
	{
			//set a pointer to stack
		node *p;
		p = stack;
			//grab its infoemation
		T x = stack->info;
			//move to the next node 
		stack = stack->next;
			//delete the previous
		delete(p);
		return x;

	}
};

#endif

