#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

Node* find_last(Node* head)
{
	//finding the last node of the list
	while(head->next!=NULL)
	{
		head=head->next;
	}
	return head;
}
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
Node* partition(Node* l,Node* h)
{
	int x=h->data;		//storing pivot element
	Node* i=l->prev;	//similar to i=l-1 implementation in array sorting
	
	for(Node* j=l;j!=h;j=j->next)		//loop from starting node to end node
	{
		if(j->data<=x)
		{
			i=(i==NULL)?l:i->next;		//if i null choose l otherwise choose next of i
			swap(&(i->data),&(j->data));	//swapping both elements
		}
	}
	i=(i==NULL)?l:i->next;
	swap(&(i->data),&(h->data));	//swapping last element
	return i;
	
}

void quickSortDLL(Node* l,Node* h)
{
	if(h!=NULL && l!=NULL && l!=h->next)
	{
		Node* p=partition(l,h);		//find partition node
		quickSortDLL(l,p->prev);	//recursice call to quicksortDLL
		quickSortDLL(p->next,h);
	}
}

void quickSort(Node* head)
{
	Node* last=find_last(head);		//finding last node of the linked list
	quickSortDLL(head,last);		//calling actual sorting function
}

void traverse(Node* head)
{
									//traversing the list
	cout<<"Contents of list -\n";
	while(head!=NULL)
	{
		cout<<head->data<<"\t";
		head=head->next;
	}
	cout<<endl;
}
void push(Node** head,int val)
{
	Node* newnode=new Node();
	newnode->data=val;
	newnode->next=*head;
	newnode->prev=NULL;
	
	if((*head)!=NULL)
		(*head)->prev=newnode;
	
	*head=newnode;
}
int main()
{
	Node* head=NULL;
	push(&head,11);
	push(&head,1);
	push(&head,8);
	push(&head,13);
	push(&head,5);
	cout<<"Before sorting: ";
	traverse(head);
	quickSort(head);
	cout<<"After sorting: ";
	traverse(head);
}
