#include<bits/stdc++.h>
using namespace std;

int binarysearch(int a[],int l,int r,int k)
{
	while(l<=r)
	{
		int m=(l+r)/2;
		if(a[m]==k)
		return m;
		else if(a[m]<k)
		{
		  l=m+1;
	    }
		else
		{
		  r=m-1;
	    }
	}
	return -1;
}
int main()
{
	int i,n,m,l1,r1;
	cout<<"Application of Binary Search Algorithm"<<endl;
	cin>>n;
	int b[n];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<"Enter the number that  you want to search"<<endl;
	cin>>m;
	int s;
	s=binarysearch(b,0,n-1,m);
	if(s == -1 )
	cout<<"The element is not present in the array"<<endl;
	else
	{
		cout<<"The element is present in the array and the index at which it is present is "<<s<<endl;
	}
	return 0;
}
