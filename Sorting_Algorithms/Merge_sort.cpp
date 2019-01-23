#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int r,int m)
{
	int i,j,size1,size2;
	size1=m-l+1;
	size2=r-m;
	int left[size1];
	int right[size2];
	for(i=0;i<size1;i++)
	{
		left[i]=a[l+i];
	}
	for(j=0;j<size2;j++)
	{
		right[j]=a[m+1+j];
	}
	i=0;
	j=0;
	int count=l;
	while(i<size1 && j<size2)
	{
		if(left[i]<=right[j])
		{
			a[count]=left[i];
			i++;
			count++;
		}
		else
		{
			a[count]=right[j];
			j++;
			count++;
		}
	}
	while(i<size1)
	{
		a[count]=left[i];
		count++;
		i++;
	}
	while(j<size2)
	{
		a[count]=right[j];
		count++;
		j++;
	}
}
void merge_sort(int a[],int l,int r)
{
	int m=(l+r)/2;
	if(l<r)
	{
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,r,m);
	}
}
int main()
{
	int i,j,n;
	cout<<"This is an implementation of Merge Sort"<<endl;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	merge_sort(a,0,n-1);
	cout<<"The array after sorting is : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	} 
	return 0;
}
