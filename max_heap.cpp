#include<iostream>
using namespace std;
void swap(int *a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
class MaxHeap{
	int capacity;		//total capacity of Heap
	int heap_size;		//current number of elements in max heap
	int *harr;			//current top element
	
	public:
	MaxHeap(int cap)
	{
		capacity=cap;
		heap_size=0;
		harr=new int[cap];
	}
	void insert(int k);
	int getMin()
	{
		return harr[0];
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
	int right_child(int i)
	{
		return (2*i)+1;
	}
	int left_child(int i)
	{
		return (2*i)-1;
	}
	void Heapify(int i);
};
void MaxHeap::insert(int k)
{
	if(heap_size>=capacity)
	{
		cout<<"OverFlow";
		return;
	}
	heap_size++;
	int i=heap_size-1;
	harr[i]=k;
	while(i!=0 && harr[parent(i)]<harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}
}
void MaxHeap::Heapify(int i)
{
	int l=left_child(i);
	int r=right_child(i);
	int large=i;
	while(l<heap_size && harr[l]>harr[large])
	{
		large=l;
	}
	while(r<heap_size && harr[r]>harr[l])
	{
		large=r;
	}
	if(large!=i)
	{
		swap(&harr[large],&harr[i]);
		Heapify(large);
	}
}
int main()
{
	MaxHeap mh(10);
	mh.insert(2);
	mh.insert(1);
	mh.insert(1);
	mh.insert(0);
	mh.insert(5);
	mh.Heapify(1);
	cout<<mh.getMin()<<"\t";
	mh.insert(101);
	cout<<mh.getMin()<<"\t";
}
