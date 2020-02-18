#include<iostream>
using namespace std;
struct Node
{
	int key;
	Node *left, *right;
};
void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);	//left subtree
		cout<<root->key<<"\t";	//value
		inorder(root->right);	//right subtree
	}
}
Node* newnode(int val)
{
	Node* temp=new Node();
	//insert value in new node
	temp->key=val;
	temp->left=temp->right=NULL; 
}
Node* insert(Node* root,int key)
{
	//if node is null, means we have reached the leaf node 
	if(root==NULL)
		return newnode(key);
		
	//if key is smaller than root node value then insert on left subtree
	if(key<root->key)
		root->left=insert(root->left,key);
		
	//if key is greater than root node value then insert on right subtree
	if(key>root->key)
		root->right=insert(root->right,key);
		
	//unchanged pointer to root 
	return root;
}
int main()
{
	Node* root=NULL;
	root=insert(root,50);
	insert(root,20);
	insert(root,10);
	insert(root,40);
	
	inorder(root);
}
