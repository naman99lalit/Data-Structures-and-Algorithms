#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int rollno;
	char name[100];
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* getnode(int roll,char name[])
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
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
     p->prev=NULL;
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
void delete_node(struct Node** head,int roll)
{
	struct Node* temp;
	struct Node* prev;
	temp=(*head);
	if((temp!=NULL)&&(temp->rollno==roll))//first node
	{
		*head=temp->next;
		(*head)->prev=NULL;
		free(temp);
		return ;
	}
	else
	{
		while((temp!=NULL)&&(temp->rollno!=roll))
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		free(temp);
		return ;
	}
}
void display(struct Node* p)
{
	struct Node* tail;
	while(p!=NULL)
	{
		cout<<"Roll No: "<<p->rollno<<"  "<<"Name: "<<p->name<<endl;
		tail=p;
		p=p->next;
	}
	cout<<"Backward List\n";
	while(tail!=NULL)
	{
	    cout<<"Roll No: "<<tail->rollno<<"  "<<"Name: "<<tail->name<<endl;
		tail=tail->prev;	
	}
}
int main()
{
	int c,i,j;
	head=NULL;
	cout<<"Deletion from a Linked List\n";
	while(1)
	{
		cout<<"Press 1 to insert data in the beginning of Linked List\n"<<"Press 2 to insert data at the end of the linked List\n"<<"Press 3 to insert a number in between of the Linked List\n"<<"Press 4 to Display the List\n"<<"Press 5 to delete the node from the list\n"<<"Press 6 to EXIT\n";
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
			int rollno;
			cout<<"Enter the roll no that you want to delete from the list\n";
			cin>>rollno;
			delete_node(&head,rollno);
		}
		else
		{
			break;
		}
	}
	return 0;
}
