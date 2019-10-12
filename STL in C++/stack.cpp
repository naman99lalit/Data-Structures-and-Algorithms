//-Stack
#include<bits/stdc++.h>
using namespace std;
int main(){
	//declaring stack
	stack<int>s;
	
	//inserting elements in the stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	//printing all the elements of the stack
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();//s.pop():deletes the toopmoost element of the stack
	}
	//Output:50 40 30 20 10
}
