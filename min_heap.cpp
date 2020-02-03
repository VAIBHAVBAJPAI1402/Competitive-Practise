#include<iostream>
#include<climits>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
class MinHeap
{
	int capacity;
	int heap_size;
	int *harr;
	
	public:
		MinHeap(int cap)
		{
			capacity=cap;
			heap_size=0;
			harr=new int[cap];
		}
		int getMin()
		{
			return harr[0];
		}
		void insert(int k);
		void Heapify(int i);
		int parent(int i)
		{
			return (i-1)/2;
		}
		int left_child(int i)
		{
			return (2*i)+1;
		}
		int right_child(int i)
		{
			return (2*i)-1;
		}
};
void MinHeap::Heapify(int i)
{
	int l=left_child(i);
	int r=right_child(i);
	int small=i;
	while(l<heap_size && harr[l]<harr[small])
	{
		small=l;
	}
	while(r<heap_size && harr[r]<harr[l])
	{
		small=r;
	}
	if(small!=i)
	{
		swap(&harr[small],&harr[i]);
		Heapify(parent(i));
	}
}
void MinHeap::insert(int k)
{
	if(heap_size>=capacity)
	{
		cout<<"OverFlow";
		return;
	}
	heap_size++;
	int i=heap_size--;
	harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}
}
int main()
{
	MinHeap mh(5);
	mh.insert(12);
	mh.insert(5);
	mh.insert(99);
	cout<<mh.getMin()<<"\t";
	mh.insert(1);
	cout<<mh.getMin()<<"\t";
}
