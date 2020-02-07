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
//insertion in after the given node where pointer to intermediate node is given
void insert_Mid(Node* head, Node* mid, int val)
{
	if(head==NULL)
	{
		cout<<"No intermediate node! cant insert";
		return;
	}
	Node* newnode=new Node();
	newnode->data=val;
	newnode->next=mid->next;
	mid->next=newnode;
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
void delete_Begin(Node** head)
{
	//delete a node from the beginning
	//just set head to next node of head
	Node* tmp;
	tmp=(*head)->next;
	*head=tmp;
}
void delete_End(Node* head)
{
	//delete a node from the end
	//just set next of second last node to NULL
	while(head->next->next!=NULL)
	{
		head=head->next;
	}
	head->next=NULL;
}
int main()
{
	Node* head=NULL;
	insert_Begin(&head,4);
	insert_Begin(&head,11);
	insert_End(&head,1);
	Node* tmp=head;
	while(tmp->data!=4)
	{
		tmp=tmp->next;
	}	
	insert_Mid(head,tmp,55);
	insert_Mid(head,tmp,12);
	traverse(head);
	
	cout<<"Deleting nodes from beginning"<<endl;
	delete_Begin(&head);
	traverse(head);
	cout<<"Deleting nodes from End"<<endl;
	delete_End(head);
	traverse(head);
	return 0;
}



