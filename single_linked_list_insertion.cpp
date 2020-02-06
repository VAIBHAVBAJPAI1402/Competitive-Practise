#include<iostream>
using namespace std;

//writing structure
struct Node
{
	int data;
	Node* next;
};
//inserting data at beginning of the list
void insert_Begin(Node** head,int val)
{
	Node* newnode=new Node();
	newnode->data=val;
	newnode->next=*head;
	//set head to newnode
	*head=newnode;
}
//insert data at the end
void insert_End(Node** head,int val)
{
	Node* newnode=new Node();
	newnode->data=val;
	newnode->next=NULL;
	if(*head==NULL)
	{
		*head=newnode;
		return;
	}
	Node* tmp=*head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newnode;
}
//traverse the list
void traverse(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}
int main()
{
	Node* head=NULL;
	insert_Begin(&head,4);
	insert_Begin(&head,11);
	insert_End(&head,1);
	traverse(head);
}



