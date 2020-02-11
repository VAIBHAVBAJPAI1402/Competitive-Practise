#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
void insert_EmptyList(Node** last,int val)
{
	if(*last!=NULL)
		return;
	else
	{
		Node* newnode=new Node();
		newnode->data=val;
		newnode->next=newnode;
		*last=newnode;
	}
}
void insert_AtEnd(Node** last,int val)
{
	
		Node* newnode=new Node();
		newnode->data=val;
		newnode->next=(*last)->next;
		(*last)->next=newnode;
		*last=newnode;
	
}
Node* traverse_prisoners(Node* last,int start)
{
	Node* p=last->next;
	do{
		if(p->data==start)
			break;
		p=p->next;
	}while(p!=last->next);
	
	return p;
}
int traverse_sweets(Node* tmp,int sweets)
{
	do{
		sweets--;
		if(sweets==0)
			break;
		tmp=tmp->next;
	}while(sweets>0);
	return tmp->data;
}
int main()
{
	int n,m,s;
	cout<<"Number of prisoners- ";
	cin>>n;
	cout<<"Number of sweets- ";
	cin>>m;
	cout<<"Start from- ";
	cin>>s;
	Node* last=NULL;
	insert_EmptyList(&last,1);
	for(int i=2;i<=n;i++)
	{
		insert_AtEnd(&last,i);
	}
	Node* tmp=traverse_prisoners(last,s);
	cout<<"Prisoner to get last sweet= "<<traverse_sweets(tmp,m);
	
	return 0;
}
