/***************
Name: David Bendel
Course: CSCE 3110.002
Assignment: program4
Due Date: 3/37/15
****************/

#include <iostream>
#include <string>

using namespace std;

struct AvlNode
{
	int sector;
	string name;
	AvlNode* left;
	AvlNode* right;
	int height;

	AvlNode( const int & sec, const string & nme ) { sector = sec; name = nme; left = right = 0; height = 0;}
};

int height( AvlNode* t )
{
	return t == nullptr ? -1 : t->height;
}

int max(int lhs, int rhs)
{
	return lhs > rhs ? lhs : rhs;
}

void printTree(AvlNode* t)
{
	if(t!=nullptr)
	{
		printTree(t->left);
		cout << t->sector << " " << t->name << endl;
		printTree(t->right);
	}
}

void rotateWithRightChild(AvlNode* & k1)
{
	AvlNode* k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	k1 = k2;

}

void rotateWithLeftChild(AvlNode * & k2)
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max( height(k2->left), height(k2->right)) + 1;
	k1->height = max( height(k1->left), k2->height) + 1;
	k2 = k1;
}

void doubleWithRightChild(AvlNode* & k1)
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

void doubleWithLeftChild( AvlNode * & k3 )
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

void balance( AvlNode* &t )
{
	if(t == nullptr)
		return;

	if( height(t->left) - height(t->right) > 1 )
		if(height(t->left->left) >= height(t->left->right))
			rotateWithLeftChild(t);
		else
			doubleWithLeftChild(t);
	else
	{
		if( height(t->right) - height(t->left) > 1 )
		{
			if( height(t->right->right) >= height(t->right->left))
			{
				rotateWithRightChild(t);
			}
			else
			{
				doubleWithRightChild(t);
			}
		}
	}

	t->height = max( height(t->left), height(t->right)) + 1;
}

void insert( const int & x, const string &y, AvlNode* &t, int &count )
{
	if( t == nullptr )
	{
		t = new AvlNode(x, y);
	}
	else if( x < t->sector ) 
	{
		count++;
		insert( x, y, t->left, count );
	}
	else if( t->sector < x )
	{
		count++;
		insert( x, y, t->right, count );
	}

	balance(t);
}

int main()
{
	int a;
	string b;
	AvlNode* root = nullptr;
	int count = 0;
	
	for(int i = 0; i < 2826; ++i)
	{
		cin >> b >> a;
		insert(a, b, root, count);
	}

	count = count / 2826;
	cout << "Average Recursive Calls: " << count << endl;

	printTree(root);

	return 0;
}




