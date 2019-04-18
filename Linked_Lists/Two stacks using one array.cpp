#include<bits/stdc++.h>
using namespace std;

class stack1
{
	int *arr;
	int top1,maxSize;
	int top2;
	public:
		stack1(int n)
		{
			maxSize=n;
			arr = new int[n];
			top1= -1;
			top2 = maxSize;
		}
		bool isFull()
		{
			if(top1+1<top2)
			{
				return false;
			}
			else
			return true;
		}
		void push1(int x)
		{
			if(isFull())
			{
				cout<<"The array is Full"<<endl;
			}
			else
			{
				top1++;
				arr[top1]=x;
			}
		}
		void push2(int x)
		{
			if(isFull())
			{
				cout<<"The array is Full"<<endl;
			}
			else
			{
				top2--;
				arr[top2]=x;
			}
		}
		void pop1()
		{
			arr[top1]=0;
			top1--;
		}
		void pop2()
		{
			arr[top2]=0;
			top2++;
		}
		void display()
		{
			for(int i=0;i<maxSize;i++)
			{
				cout<<arr[i]<<endl;
			}
		}
};
int main()
{
	stack1 s(5);
	s.push1(12);
	s.push2(13);
	s.push1(14);
	s.push2(15);
	s.push1(16);
	s.display();
	s.push2(17);
	return 0;
}
