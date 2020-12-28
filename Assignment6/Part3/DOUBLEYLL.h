/*********************************************
Amber Kimberling
AssignmentNo6Pt3
CMPS 400

Insert a scentence into a doubley linked list and
determine whether it is a Palindrome
*********************************************/
#ifndef DOUBLEYLL
#define DOUBLEYLL
//creating a template class
template<class T>
class double_llist {
private:
	struct node
	{
		T info;
		node *next, *back;
	};
	node* dlist = NULL;

public:
	void insert(T x)
	{
		node *p, *temp;
		temp = new node;
		temp->info = x; 
		temp->next = NULL; 
		temp->back = NULL;
		if (dlist == NULL)
		{
			dlist = temp;
		}
		else
		{
			p = dlist;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
			temp->back = p;
		}

	}
	void display()
	{
		node *p = dlist;
		while (p != NULL)
		{
			cout << p->info << "-->"; 
			p = p->next;
		}
		cout << "NULL\n";
	}
	void delete_info(T x)
	{
		//delete the node with info=x
		node *p, *q;
		p = q = dlist;
		while (p->info != x)
		{
			q = p; p = p->next;
		}
		if (p == dlist)
		{
			//x is the first node
			dlist = p->next;
			dlist->back = NULL;
			delete p;
		}
		else
		{
			q->next = p->next;
			p->next->back = q;
			delete p;
		}
	}
	bool search(T x)
	{
		node *p = dlist;
		while (p != NULL)
		{
			if (p->info == x) return true;
			p = p->next;
		}
		return false;
	}
	bool isPalindrome(node *left)
	{
		if (left == NULL)
			return true;
 
		node *right = left;
		while (right->next != NULL)
			right = right->next;

		while (left != right)
		{
			if (left->info != right->info)
				return false;

			left = left->next;
			right = right->back;
		}

		return true;
	}

	bool isPalindrome() { node *p = dlist;  return isPalindrome(p); }
};

#endif