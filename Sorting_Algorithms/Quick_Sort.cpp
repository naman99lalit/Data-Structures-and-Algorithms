#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int l,int r)
{
	int i,j,k;
	i=(l-1);
	k=a[r];
	for(j=l;j<r;j++)
	{
		if(a[j]<=k)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	
	return (i+1);
}
void quicksort(int a[],int l,int r)
{
	if(l<r)
	{
		int q=partition(a,l,r);
		quicksort(a,l,q-1);
		quicksort(a,q+1,r);
	}
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int i,j,k,n;
	cout<<"Enter the no of elements in the array\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	quicksort(a,0,n-1);
	print(a,n);
	return 0;
}
