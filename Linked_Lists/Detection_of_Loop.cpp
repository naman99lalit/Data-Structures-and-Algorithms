#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node * next;
};

void insert(struct Node** head,int data)
{
	struct Node* temp=new Node;
	if(*head==NULL)
	{
		*head=temp;
		temp->data=data;
		temp->next=NULL;
	}
	else
	{
		struct Node* p=*head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->data=data;
		temp->next=NULL;
	}
}
void check(struct Node* head)
{
	int count=0;
	struct Node* slow=head;
	struct Node* fast=head;
	while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
	    {
		  count=1;
		  break;
	    }
	}
	if(count==1)
	cout<<"Loop is present in the List\n";
	else
	cout<<"Loop is not there in the list\n";
}
int main()
{
	int i,j,n,data;
	struct Node* head=NULL;
	cout<<"Enter the number of elements in the linked list\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter the data\n";
		cin>>data;
		insert(&head,data);
	}
	head->next->next->next->next=head;
	check(head);
	return 0;
}	
