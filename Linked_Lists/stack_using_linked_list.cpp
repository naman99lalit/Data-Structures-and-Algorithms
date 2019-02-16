#include<bits/stdc++.h>

struct Node
{
	int item;
	struct Node* next;
};

struct Node* head;
int size;

void insertathead(){
	struct Node* ptr;
	ptr = new Node;
	printf("Enter data : ");
	scanf("%d",&ptr->item);
	printf("\n");
	if(head == NULL){
		head = ptr;
		ptr->next = NULL;
		return;
	}
	ptr->next = head;
	head = ptr;
}

void pop(){
	if(head==NULL){
		printf("UnderFlow\n");
		return;
	}
	if(head->next == NULL){
		head=NULL;
		return;
	}
	else{
	struct Node* temp;
    temp=head;
    temp=temp->next;
    head=temp;
    }
}
void print(){
	struct Node* temp;
	temp = head;
	printf("List : ");
	while(temp!=NULL){
		printf("%d ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head=NULL;
	while(1){
		printf("Enter choice\n1.Insert\n2.Pop\n3.Print\n");
		int ch;
		scanf("%d",&ch);
		if(ch==1){
		insertathead();
		}
		else if(ch==2){
			pop();	
		}
		else if(ch==3){
			print();
		}
	}
	return 0;
}
