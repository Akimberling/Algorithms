#ifndef BSTREE
#define BSTREE

class BTREE {

private:
	struct node {
		string month;
		node *left, *right;
	};
	node*root;

public:
	BTREE() { root = NULL; }

	void insert(node*& r, string x)
	{
		node *p = new(node);
		p->month = x;
		p->left = NULL;
		p->right = NULL;
		if (r == NULL)
			r = p;
		else
		{
			if (x < r->month)insert(r->left, x);
			if (x > r->month)insert(r->right, x);
		}
	}
	void displayInOrder(node * &r)
	{
		//LC P RC
		if (r != NULL)
		{
			displayInOrder(r->left);
			cout << r->month << " ";
			displayInOrder(r->right);
		}
	}
	void sideWay(node* r, int count)
	{
		if (r != NULL)
		{
			sideWay(r->right, count += 5);
			cout << setw(count) << r->month << endl;
			sideWay(r->left, count);
		}
	}
	bool sameTrees(node *r1, node *r2)
	{
		if (r1 == NULL && r2 == NULL) return true;
		if (r1 == NULL || r2 == NULL) return false;
		
		return (r1-> month == r2-> month) &&
			sameTrees(r1->left, r2->left) &&
			sameTrees(r1->right, r2->right);
	}


	bool sameTrees(BTREE Jan2Dec, BTREE Dec2Jan) { return sameTrees(Jan2Dec.root, Dec2Jan.root); }
	void insert(string x) { insert(root, x); }
	void displayInOrder() { displayInOrder(root); }
	void sideWay(int count) { sideWay(root, count); }

};


#endif 
