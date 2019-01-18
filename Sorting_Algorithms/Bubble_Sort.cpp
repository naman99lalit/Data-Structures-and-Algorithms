#include<bits/stdc++.h>
using namespace std;

void bubblesort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int i,n,k;
	cout<<"Application of Bubble sort Algorithm"<<endl;
	cin>>n;
	int b[n];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	bubblesort(b,n);
	return 0;
}
