#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int rollno;
	char name[100];
	struct Node* next;
};
struct Node* head;
struct Node* getnode(int rollno,char name[])
{
	struct Node* p= new Node;
	p->rollno=rollno;
	strcpy(p->name,name);
	return p;
}
void insert_begin(struct Node** head,int rollno,char name[])
{
	struct Node* p=getnode(rollno,name);
	p->next=*head;
	*head=p;
}
void insert_end(struct Node** head,int rollno,char name[])
{
	struct Node* p=getnode(rollno,name);
	p=*head;
	p->next=NULL;
	if(*head==NULL)
	{
		*head=p;
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
	}
}
void search(struct Node** head,int rollno)
{
	struct Node* temp=*head;
	if(*head==NULL)
	{
		cout<<"Element is not present in the list\n";
	}
	else
	{
		int count=1;
		while(temp!=NULL)
		{
			if(temp->rollno==rollno)
			{
				cout<<"Element is present in the list\n";
				return ;
			}
			temp=temp->next;
		}
		cout<<"Element is not present in the list\n";
	}
}
int main()
{
	int i,j,c;
	int rollno;
	head=NULL;
	char name[100];
	cout<<"Searching an element in the linked list\n";
	while(1)
	{
	   cout<<"Press 1 to insert the node in the beginning of the list\n"<<"Press 2 to insert the node at the end of the list\n"<<"Press 3 to search the element in the list\n"<<"Press 4 to EXIT\n";
	   cin>>c;
	   if(c==1)
	   {
	   	cout<<"Enter the name of the person\n";
	    cin>>name;
	    cout<<"Enter the roll no that you want to add in the list\n";
	    cin>>rollno;
	   	insert_begin(&head,rollno,name);
	   }
	   else if(c==2)
	   {
	   	cout<<"Enter the name of the person\n";
	    cin>>name;
	    cout<<"Enter the roll no that you want to add in the list\n";
	    cin>>rollno;
	    insert_end(&head,rollno,name);
	   }
	   else if(c==3)
	   {
	   	cout<<"Enter the roll no that you want to search in the list\n";
	   	cin>>rollno;
	   	search(&head,rollno);
	   }
	   else
	   {
	   	break;
	   }
	}
	return 0;
}
