#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int rollno;
	char name[30];
	struct Node* next;
};
struct Node* head;
int countnodes(int roll,char s[])
{
	struct Node* temp=head;
	int count=0;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
struct Node* getnode(int roll,char name[])
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->rollno=roll;
	strcpy(p->name,name);
	return p;
}
void insert_begin(int roll,char name[])
{
    struct Node* p=getnode(roll,name);
    if(head==NULL)
    {
    	head=p;
    	return;
	}
	p->next=head;
	head=p;	
}
void insert_end(int roll,char name[])
{
   struct Node* p=getnode(roll,name);
   if(head==NULL)//list is empty
   {
     head=p;
	 p->next=NULL;	
   }
   else
   {
   	struct Node* temp=head;
   	while(temp->next!=NULL)
   	{
   		temp=temp->next;
	}
	temp->next=p;
   }	
}
void display()
{
	struct Node* p;
	p=head;
	while(p!=NULL)
	{
		cout<<"Roll No: "<<p->rollno<<"  "<<"Name: "<<p->name<<endl;
		p=p->next;
	}
}
int main()
{
	int i,j;
	int c;
	head=NULL;
	cout<<"Inserting Data In A Linked List\n";
	while(1)
	{
		cout<<"Press 1 to insert data in the beginning of Linked List\n"<<"Press 2 to insert data at the end of the linked List\n"<<"Press 3 to insert a number in between of the Linked List\n"<<"Press 4 to Display the List\n"<<"Press 5 to Exit\n";
        cin>>c;
        if(c==1)
        {
        	char name[100];
        	int rollno;
        	cout<<"Enter the name of the student\n";
        	cin>>name;
			cout<<"Enter the Roll no of the student\n";
			cin>>rollno;
			insert_begin(rollno,name);
		}
		else if(c==2)
		{
			char name[100];
        	int rollno;
        	cout<<"Enter the name of the student\n";
        	cin>>name;
			cout<<"Enter the Roll no of the student\n";
			cin>>rollno;
			insert_end(rollno,name);
		}
		else if(c==3)
		{
			char name[100];
        	int rollno;
        	cout<<"Enter the name of the student\n";
        	cin>>name;
			cout<<"Enter the Roll no of the student\n";
			cin>>rollno;
			//insert_between(rollno,name);
		}
		else if(c==4)
		{
			display();
		}
		else if(c==5)
		{
			break;
		}
 	}
 	return 0;
}
