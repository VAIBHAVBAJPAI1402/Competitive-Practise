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
		void deletekey(int i);
		int extractMin();
		void decreasekey(int val, int i);
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
	while(l<heap_size && harr[l]<harr[i])
	{
		small=l;
	}
	while(r<heap_size && harr[r]<harr[small])
	{
		small=r;
	}
	if(small!=i)
	{
		swap(&harr[small],&harr[i]);
		Heapify(small);
	}
}
void MinHeap::insert(int k)
{
	if(heap_size==capacity)
	{
		cout<<"OverFlow";
		return;
	}
	heap_size++;
	int i=heap_size-1;
	harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}
}
void MinHeap::decreasekey(int val,int i)
{
	harr[i]=val;
	while(i!=0 && harr[i]<harr[parent(i)])
	{
		swap(&harr[i],&harr[parent(i)]);
		i=parent(i);
	}
}
int MinHeap::extractMin()
{
	if(heap_size==0)
	{
		return INT_MAX;
	}
	if(heap_size==1)
	{
		heap_size--;
		return harr[0];
	}
	
	//if heap has more than 1 element
	int root=harr[0];			//store 
	harr[0]=harr[heap_size-1];	//store max value in place of root and heapify it
	heap_size--;
	Heapify(0);					//heapify the heap 
	return root;
	
}
void MinHeap::deletekey(int i)
{
	decreasekey(INT_MIN, i);
	extractMin();
}
int main()
{
	MinHeap mh(10);
	mh.insert(10);
	mh.insert(5);
	mh.insert(101);
	cout<<mh.getMin()<<"\t";
	mh.insert(1);
	cout<<mh.getMin()<<"\t";
	mh.decreasekey(12,2);
	cout<<mh.extractMin()<<"\t";
	mh.deletekey(2);
	cout<<mh.getMin()<<"\t";
}
