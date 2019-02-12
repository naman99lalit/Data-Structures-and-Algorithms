#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int rollno;
	char name[30];
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
int countnodes(struct Node** head)
{
	struct Node* temp=*head;
	int count=1;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
struct Node* getnode(int roll,char name[])
{
	struct Node* p=new Node;
	p->rollno=roll;
	strcpy(p->name,name);
	return p;
}
void insert_begin(struct Node** head,int roll,char name[])
{
    struct Node* p=getnode(roll,name);
	p->next=*head;
	p->prev=NULL;
	if((*head)!=NULL)
	{
		(*head)->prev=p;
	}
	*head=p;	
}
void insert_end(struct Node** head,int roll,char name[])
{
   struct Node* p=getnode(roll,name);
   p->next=NULL;
   if(*head==NULL)//list is empty
   {
     *head=p;
     p->prev=*head;
	 return;	
   }
   else
   {
   	struct Node* temp=*head;
   	while(temp->next!=NULL)
   	{
   		temp=temp->next;
	}
	temp->next=p;
	p->prev=temp;
	return;
   }	
}
void insert_between(struct Node* head,int roll,char name[],int k)
{
	if(head->next==NULL)
	{
	  cout<<"You need to enter atleast one rollno in the list\n";
	  return;	
	}
	else
	{
	   struct Node* temp=head;
	   while(temp->rollno!=k)
	   {
	   	temp=temp->next;
	   }
	   struct Node* p=getnode(roll,name);
	   p->next=temp->next;
	   temp->next=p;	
	   p->prev=temp;
	}
}
void display(struct Node* p)
{
	cout<<"Forward Linked List\n";
	struct Node* tail;
	while(p!=NULL)
	{
		cout<<"Roll No: "<<p->rollno<<"  "<<"Name: "<<p->name<<endl;
		tail=p;
		p=p->next;
	}
	cout<<"Reverse Linked List\n";
	while(tail!=NULL)
	{
		cout<<"Roll No: "<<tail->rollno<<"  "<<"Name: "<<tail->name<<endl;
		tail=tail->prev;
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
		cout<<"Press 1 to insert data in the beginning of Linked List\n"<<"Press 2 to insert data at the end of the linked List\n"<<"Press 3 to insert a number in between of the Linked List\n"<<"Press 4 to Display the List\n"<<"Press 5 to Count the no of nodes in the list\n"<<"Press 6 to Exit\n";
        cin>>c;
        if(c==1)
        {
        	char name[100];
        	int rollno;
        	cout<<"Enter the name of the student\n";
        	cin>>name;
			cout<<"Enter the Roll no of the student\n";
			cin>>rollno;
			insert_begin(&head,rollno,name);
		}
		else if(c==2)
		{
			char name[100];
        	int rollno;
        	cout<<"Enter the name of the student\n";
        	cin>>name;
			cout<<"Enter the Roll no of the student\n";
			cin>>rollno;
			insert_end(&head,rollno,name);
		}
		else if(c==3)
		{
			char name[100];
        	int rollno,k;
        	cout<<"Enter the name of the student\n";
        	cin>>name;
			cout<<"Enter the Roll no of the student\n";
			cin>>rollno;
			cout<<"Enter the roll no after which you want to add the element\n";
			cin>>k;
			insert_between(head,rollno,name,k);
		}
		else if(c==4)
		{
			display(head);
		}
		else if(c==5)
		{
			//display_back();
			int m=countnodes(&head);
			cout<<m<<endl;
		}
		else
		{
			break;
		}
 	}
 	return 0;
}
