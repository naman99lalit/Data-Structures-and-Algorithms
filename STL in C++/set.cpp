//STL-sets
#include<bits/stdc++.h>
using namespace std;
int main(){
	//declaring the set container
	set<int>s;
	//inserting elements
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	//iterating the set using iterators
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	//output:1 2 3 (Set only stores unique elements)
}
