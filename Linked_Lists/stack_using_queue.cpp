#include<bits/stdc++.h>
using namespace std;
	
int main()
{
	queue<int> q1,q2;
	queue<int> temp;
	int size=0;
	cout<<"Implementation of Stack using Queue\n";
	while(1)
	{
		cout<<"Press 1 to push an element to the stack\n"<<"Press 2 to pop an element from the stack\n"<<"Press 3 to display the stack\n"<<"Press 4 to Exit\n";
		char ch;
		cin>>ch;
		if(ch=='1')
		{
			cout<<"Enter the element that you want to push\n";
			int elem;
			cin>>elem;
			q1.push(elem);
			while(!q2.empty())
			{
			   q1.push(q2.front());
			   q2.pop();
			}
			temp=q1;
			q1=q2;
			q2=temp;
		}
		else if(ch=='2')
		{
			cout<<"The element is popped from the stack\n";
			q2.pop();
		}
		else if(ch=='3')
		{
			cout<<"The elements of the stack are : ";
			queue<int> disp1,disp2;
			disp1 = q2;
			while(!disp1.empty())
			{
				cout<<disp1.front()<<" ";
				disp1.pop();
			}
			cout<<endl;
		}
		else break;
	}
	return 0;
}
