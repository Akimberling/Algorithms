/******************************************************
Amber Kimberling
Assignment No7 Pt 1
CMPS 400

Program to
1) insert Jan -> Dec into a BST
2) display in inorder traversal
3) display the height
4) display ansestors or december
5) delete leaves and display sideways
6) count the number of nodes
******************************************************/
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
		//constructor of the class
	BTREE() { root = NULL; }
		//method to insert items into the tree
	void insert(node*& r, string x)
	{	
			//create a new node
		node *p = new(node);
			//set the node to the value passed to the method
		p->month = x;
			//set its leaves to null
		p->left = NULL;
		p->right = NULL;
			//determine if there are no nodes
		if (r == NULL)
			r = p;
		else
		{
				//continue inserting 
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
			//if the root is noot null
		if (r != NULL)
		{	
				//continue displaying each side of the tree sideways
			sideWay(r->right, count += 5);
			cout << setw(count) << r->month << endl;
			sideWay(r->left, count);
		}
	}
	int countNodes(node * &r)
	{
			//if the root is null the count is 0
		if (r == NULL) return 0;
			//count the nodes recursively
		else return 1 + countNodes(r->right) + countNodes(r->left);
	}
	int treeHeight(node *& r)
	{		
			//if the rot is null then the tree has no height
		if (r == NULL) return -1;
			//count the height of the tree
		else return 1 + max(treeHeight(r->right), treeHeight(r->left));
	}	
		//display the ancestors
	bool showAncestor(node* r, string target) 
	{
			//if the root is null there are no ancestors
		if (r == NULL) return false;
			//if the node is the target then there are ancestors
		if (r->month == target) return true;
			//continue checking for ancestors
		if (showAncestor(r->left, target) ||
			showAncestor(r->right, target))
		{	
				//display the content of each node
			cout << r->month << " ";
			return true;
		}
		else
			return false;
	}
		//remove the leaves
	node * remLeaves(node *& r)
	{	
			//if the root is null then there are no leaves
		if (r == NULL)
			return NULL;
			//if both sides are null then remove said node
		if (r->left == NULL && r->right == NULL) {
			free(r);
			return NULL;
		}

			// else recursively delete in left and right 
		r->left = remLeaves(r->left);
		r->right = remLeaves(r->right);

		return r;
	}
		//overloaded dummy functions to pass the root
	bool showAncestor(string target) {  return showAncestor(root, target); }
	void insert(string x) { insert(root, x); }
	void displayInOrder() { displayInOrder(root); }
	void sideWay(int count) { sideWay(root, count); }
	void remLeaves() { remLeaves(root); }
	int countNodes() { return countNodes(root); }
	int treeHeight() { return treeHeight(root); }

};


#endif 
