#include<iostream>
#include<string.h>
using namespace std;
int instring(char ch,char* sr)
{
	int len=strlen(sr);
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(ch==sr[i])
			flag=1;
	}
	return flag;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s1,s2;
		cin>>s1;
		int l1=strlen(s1);
		cin>>s2;
		int l2=strlen(s2);
		int del=0;
		for(int i=0;i<l1;i++)
		{
			if(instring(s1[i],s2))
				continue;
			else
				del++;
		}
		for(int i=0;i<l2;i++)
		{
			if(instring(s2[i],s1))
				continue;
			else
				del++;
		}
		if(del==0)
		cout<<"Anagram";
		else
		cout<<"characters to be deleted: "<<del;
	}
	
}
