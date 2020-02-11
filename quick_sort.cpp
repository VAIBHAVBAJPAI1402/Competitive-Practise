#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int l,int h)
{
	int tmp=arr[h];
	int i=l-1;
	for(int j=l;j<=h-1;j++)
	{
		if(arr[j]<tmp)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}
void quicksort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=partition(arr,l,h);
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,h);
	}
}
int main()
{
	int arr[]={5,3,2,6,11,1};
	quicksort(arr,0,5);
	cout<<"Sorted array -\n";
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<"\t";
	}
}
