/*********************************************
Amber Kimberling
AssignmentNo6Pt2
CMPS 400

Insert a scentence into a linked list and 
determine whether it is a Palindrome
*********************************************/
#ifndef QUELLIST
#define QUELLIST
//creating a template class
template<class T>
class que_llist
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
	que_llist() { stack = NULL;}
	void deleteList() { stack = NULL; }
	//check if the linked list stack is empty
	bool empty_s() { return(stack == NULL) ? true : false; }
	//inserting items into the list
	void insert( T x)
	{
		//insert x at the rear of the list
		node* r = new node;
		r->info = x; r->next = NULL;
		if (stack == NULL)
			stack = r;
		else
		{
			//make p to point at the rear node
			node* p = stack;
			while (p->next != NULL)
				p = p->next;
			p->next = r;
		}
	}
	void reverse(T x) {

		//insert x in front of list
		node* r = new node;
		r->info = x; 
		r->next = NULL;
		if (stack == NULL)
			stack = r;
		else
		{
			r->next = stack; 
			stack = r;
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
		//find the middle node
	node* findMiddleNode(node* r)
	{
			//declare and initialize nodes
		node *t1, *t2;
		t1 = t2 = r;
			//find out if the next Node is NULL
		while (t1->next != NULL)
		{
				//set t1 to the next next item
			t1 = t1->next->next;
				//exit out of the loop is null
			if (t1 == NULL) break;
				//else move t2 to the next node
			t2 = t2->next;
		}
		return t2;
	}
		//dummy method to return the middle character
	char findMiddleNode() { 
		
		node *t;
		t = findMiddleNode(stack);
		char letter = t->info;
		return letter;
	
	}
	bool isPalindrome(struct Node *left) 
{ 
    if (left == NULL) 
       return true; 
  
    // Find rightmost node 
    struct Node *right = left; 
    while (right->next != NULL) 
        right = right->next; 
  
    while (left != right) 
    { 
        if (left->data != right->data) 
            return false; 
  
        left = left->next; 
        right = right->prev; 
    } 
  
    return true; 
} 
};

#endif

