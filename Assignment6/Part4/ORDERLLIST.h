#ifndef ORDERLLIST
#define ORDERLLIST
//creating a template class
template<class T>
class order_llist
{
private:
	//declaring the nodes structure
	struct node
	{
		T info;
		node *next;
	};
	//pointing a node to the linked list of nodes
	node *order;
public:
	//constructor
	order_llist() { order = NULL; }
	//check if the linked list order is empty
	bool empty_s() { return(order == NULL) ? true : false; }
	//inserting items into the list
	void insert(T x)
	{
		//create a new node
		node *r = new(node);
		//initialize its info and set the next valule to null
		r->info = x;
		r->next = NULL;
		//if the order is null
		node* p = order; node* q = order;
		if (order == NULL)
			//set the order to p
			order = r;
		else
		{
			while (p != NULL && x > p->info)
			{
				q = p; p = p->next;
			}
			if (p == q)
			{  //insert in front
				r->next = p; order = r;
			}
			else
			{   //insert at the rear
				r->next = p; q->next = r;
			}
		}
	}
	//displaying the linked list
	void display()
	{
		//create a temporary pointer to the linked list
		node* t = order;
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
		//set a pointer to order
		node *r;
		r = order;
		//grab its infoemation
		T x = order->info;
		//move to the next node 
		order = order->next;
		//delete the previous
		delete(r);
		return x;
	}
	void unionSet(node* b, node* c)
	{
		order_llist<int> UNION;
		while (b != NULL && c != NULL)
		{
			if (b->info < c->info)
			{
				UNION.insert(b->info); b = b->next;
			}
			else if (c->info < b->info)
			{
				UNION.insert(c->info); c = c->next;
			}
			else
			{
				UNION.insert(b->info); b = b->next; c = c->next;
			}
		}
		while (b != NULL)
		{
			UNION.insert(b->info); b = b->next;
		}
		while (c != NULL)
		{
			UNION.insert(c->info); c = c->next;
		}
		UNION.display();
	}
	void intersectionSet(node* b, node* c)
	{
		node *temp2 = c;
		order_llist<int> INTERSECT;
		while (temp2 != NULL) {
			node *temp = b;
			while (temp != NULL)
			{
				if (temp->info == temp2->info)
				{
					INTERSECT.insert(temp->info); 
				}
				temp = temp->next;
			}
			temp2 = temp2->next;
			
		}
		if (!INTERSECT.empty_s())
			INTERSECT.display();
		else
			cout << "Nothing to is the same in each set" << endl;
	}
	void intersectionSet(order_llist<int> setA, order_llist<int> setB) {
		intersectionSet(setA.order, setB.order);
	}
	void unionSet(order_llist<int> setA, order_llist<int> setB) { 
		unionSet(setA.order, setB.order);
	}
};
#endif