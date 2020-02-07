#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

//inserting node at begining of the list
void insert_Begin(Node** head, int val)
{
	Node* newnode=new Node();
	newnode->data=val;
	newnode->next=*head;	//set next of newnode to head
	newnode->prev=NULL;		
	*head=newnode;			//reposition head to newnode
}
void insert_End(Node** head, int val)
{
	//create a newnode
	Node* newnode=new Node();
	newnode->data=val;
	newnode->next=NULL;
	
	//if list is empty
	if(*head==NULL)
	{
		newnode->prev=NULL;
		*head=newnode;
		return;
	}
	
	//if node has some content
	Node* tmp=*head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;	//traversing the list to reach end node
	}
	tmp->next=newnode;	//set next of last node to newnode
	newnode->prev=tmp;	//set prev of newnode to last node of list
}
void traverse(Node* head)
{
	//printing contents of the list
	cout<<"List contents-"<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}
int main()
{
	Node* head=NULL;
	insert_Begin(&head,1);
	insert_Begin(&head,2);
	insert_Begin(&head,3);
	insert_Begin(&head,4);
	insert_Begin(&head,5);
	traverse(head);
	insert_End(&head,10);
	insert_End(&head,11);
	insert_End(&head,12);
	traverse(head);
}
