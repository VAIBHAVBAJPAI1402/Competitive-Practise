#include<iostream>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main()
{
	string str;
	cin>>str;		//input numbers separated by commas
	stringstream ss(str);
	vector<int> nums;
	int a;
	char ch;
	while(ss>>a)
	{
		nums.push_back(a);
		ss>>ch;
	}
	cout<<"Numbers in the input stream: "<<endl;
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<endl;
	}
	return 0;
	
}
