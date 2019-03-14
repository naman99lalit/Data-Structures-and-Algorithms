#include <bits/stdc++.h>
using namespace std; 

int array[100], n=100, top=-1;
void push(int value) 
{
   if(top>=n-1)
      cout<<"Stack Overflow"<<endl; 
   else 
   {
      top++;
      array[top]=value;
   }
}
void pop() 
{
   if(top<=-1)
      cout<<"Stack Underflow"<<endl;
   else
    {
      cout<<"The Element popped from the stack is "<< array[top] <<endl;
      top--;
   }
}
void display()
{
   if(top>=0)
    {
      cout<<"The elements in the stack are:";
      for(int i=top; i>=0; i--)
         cout<<array[i]<<" ";
         cout<<endl;
   } 
   else
      cout<<"The Stack is empty";
}
int main()
{
   int ch, val; 
   cout<<"Press 1 to Push element in the stack"<<endl;
   cout<<"Press 2 to Pop element from the stack"<<endl;
   cout<<"Press 3 to Display elements in the stack"<<endl;
   cout<<"Press 4 to Exit from the stack"<<endl;
   do {
      cout<<"Enter the choice: "<<endl;
      cin>>ch;
      switch(ch)
	   {
         case 1:
		 {   
            cout<<"Enter the value that you want to push:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2:
		 {
            pop();
            break;
         }
         case 3: 
		 {
            display();
            break;
         }
         case 4: 
		 {
            cout<<"Exit"<<endl;
            break;
         }
         default: 
		 {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4); 
      return 0;
}
