#include<iostream>
struct Node
{
	int key;
	Node *left, *right;
};

Node* newnode(int key)
{
	//inserting newnode at leaf
	Node* temp=new Node();
	temp->key=key;
	temp->left=temp->right=NULL;
	return temp;
	
}
Node* insert(Node* root, int key)
{
	//if node is null
	if(root==NULL)
		return newnode(key);
	
	if(key<root->key)
	{
		root->left=insert(root->left,key);
	}
	if(key>root->key)
	{
		root->right=insert(root->right,key);
	}
	
	return root;
	
}

Node* deleteNode(Node* node,int key)
{
	//if node is null then return this node
	if(node==NULL)
		return node;
		
	//if node has only left child or no child at all then copy the contents of child node and delete child
	if(key<node->key)
	{
		node->left=deleteNode(node->left,key);
	}
	else if(key>node->key)
	{
		node->right=deleteNode(node->right,key);
	}
	else
	{
		//if key is equal to value at node
		
	}
	
}

int main()
{
	Node* root=NULL;
	root=insert(root,20);
	insert(root,10);
	insert(root,30);
	insert(root,50);
	insert(root,40);
	insert(root,10);
	insert(root,30);
	
	//printing the contents of binary tree
	cout<<"Contents -\n";
	inorder(root);
	
	//delete the node with key 20
	root=deleteNode(root,20);
	cout<<"Contents of modified tree -\n";
	inorder(root);
	
	
}
