#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insert_atEnd(Node** head, Node** last,int val)
{
    Node* newnode=new Node();
    newnode->data=val;
    newnode->next=*head;
    (*last)->next=newnode;
}
void insert_First(Node** head,Node** last,int val)
{
    Node* newnode=new Node();
    newnode->data=val;
    newnode->next=*head;
    *last=newnode;
    *head=newnode;
}
void traverse(Node* head,Node* last)
{
	while(head!=last)
	{
		cout<<head->data<<"\t";
		head=head->next;
	}
	cout<<head->data;
	
}
int main()
{
	Node* head=NULL;
	Node* last=NULL;
	int n,m,s;
	cin>>n;
	cin>>m;
	cin>>s;
	insert_First(&head,&last,1);
    for(int i=2;i<=n;i++)
    {
        insert_atEnd(&head,&last,i);
    }
    traverse(head,last);
	
}
