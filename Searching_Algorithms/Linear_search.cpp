#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,i;
	cout<<"This is an implementation of Linear Search"<<endl;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the item that you want to search in the array"<<endl;
	cin>>m;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"Element found in the array"<<endl;
	}
	else
	cout<<"Element not present in the array"<<endl;
	return 0;
}
