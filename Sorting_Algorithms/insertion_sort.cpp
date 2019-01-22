#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	cout<<"Enter the number of elements in the array"<<endl;
	cin>>n;
	int a[n];
	cin>>a[0];
	int k;
	for(j=1;j<n;j++)
	{
		cin>>a[j];
		int m=a[j];
			for(k=j-1;k>=0;k--)
			{
				if(m<a[k])
				{
				   a[k+1]=a[k];	
				}
				else
				{
				 break;
			    }
			}
			a[k+1]=m;
			for(int i=0;i<=j;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
	}
}
 
