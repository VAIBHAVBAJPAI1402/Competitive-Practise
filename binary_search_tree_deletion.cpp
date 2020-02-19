#include<iostream>
using namespace std;
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
Node* minValueNode(Node* root)
{
	Node* cur=root;
	while(cur!=NULL && cur->left!=NULL)
	{
		cur=cur->left;
	}
	return cur;
	
}
Node* deleteNode(Node* node,int key)
{
	//if node is null then return this node
	if(node==NULL)
		return node;
		
	//if 
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
		//if key is equal to value at node and has one child or no
		if(node->left==NULL)
		{
			Node* temp=node->right;
			free(node);
			return temp;
		}
		else if(node->right==NULL)
		{
			Node* temp=node->left;
			free(node);
			return temp;
		}
		//if node has both children then replace it with next inorder value
		Node* temp=minValueNode(node->right);
		//replace it with inorder successor
		node->key=temp->key;
		//delete the inorder successor
		node->right=deleteNode(node->right,temp->key);
	}
	
}

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<"\t";
		inorder(root->right);	
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
	cout<<endl;
	//delete the node with key 20
	root=deleteNode(root,20);
	cout<<"Contents of modified tree -\n";
	inorder(root);
	cout<<endl;
	return 0;
	
}
