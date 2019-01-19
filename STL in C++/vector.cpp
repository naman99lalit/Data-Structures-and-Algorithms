#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	vector<int> :: iterator it;
	v.push_back(5);
	v.push_back(10);
	v.push_back(19);
	v.push_back(2);
	v.push_back(12);
	cout<<"Sorting A Vector in C++"<<endl;
	sort(v.begin(),v.end());
	for(it=v.begin();it<v.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}