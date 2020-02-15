#include<iostream>
using namespace std;
struct tree		//structure to define node of tree
{
	int data;
	tree* left;
	tree* right;
};
tree* insert(int val)		//insertion in the tree
{
	tree* newnode=new tree();
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}
//inorder traversal of tree
void inorder_traversal(tree* root)
{
	//if root is null then return
	if(root==NULL)
		return;
	inorder_traversal(root->left);
	cout<<root->data<<"\t";
	inorder_traversal(root->right);
}
//preorder traversal of tree
void preorder_traversal(tree* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<"\t";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}
//postorder traversal of tree
void postorder_traversal(tree* root)
{
	if(root==NULL)
		return;
	preorder_traversal(root->left);
	preorder_traversal(root->right);
	cout<<root->data<<"\t";
}
int main()
{
	tree* root;
	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	root->left->left=insert(4);
	cout<<"Inorder traversal-\n";
	inorder_traversal(root);
	cout<<endl;
	cout<<"Preorder traversal-\n";
	preorder_traversal(root);
	cout<<endl;
	cout<<"Postorder traversal-\n";
	postorder_traversal(root);
	cout<<endl;
	return 0;
}
