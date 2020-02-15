#include<iostream>
using namespace std;
struct tree
{
	int data;
	tree* left;
	tree* right;
};
tree* insert(int val)
{
	tree* newnode=new tree();
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}

int traverse(tree* root)
{
	return root->data;
}

int main()
{
	tree* root;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	
	cout<<traverse(root);
	
	return 0;
}
