#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	cout<<"Enter the no of elements in the array"<<endl;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int count=0,flag=0;
	for(i=0;i<n;i++)
	{
		int temp;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j+1]<a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				count++;
				flag=1;
			}
		}
			if(flag==0)
			{
				break;
			}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n"<<count;
	return 0;
}
