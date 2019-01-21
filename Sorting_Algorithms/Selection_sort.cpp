#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void selection_sort(int a[],int n)
{
	int index;
	for(int i=0;i<n;i++)
	{
		index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[index])
			{
				index=j;
			}
		}
		swap(&a[i],&a[index]);
	}
}
int main()
{
	int i,j,n;
	cout<<"This is Selection Sort"<<endl;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	selection_sort(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
