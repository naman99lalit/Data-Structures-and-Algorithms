#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};
struct node* temp2=NULL;
struct node* newnode(int item)
{
	struct node *temp = new node;
	temp->key=item;
	temp->right=NULL;
	temp->left=NULL;
}
struct node* insertnode(struct node *node, int item)
{
	if(node==NULL)
	{
		return newnode(item);
	}
	else if((node->key)<item)
	{
		node->right=insertnode(node->right,item);
	}
	else if((node->key)>item)
	{
		node->left=insertnode(node->left,item);
	}
	return node;
}
int search(struct node* node,int item)
{
	if(node==NULL)
	{
		return 0;
	}
	else if((node->key)==item)
	{
	    return 1;
    }
	else if((node->key)<item)
	{
		return search((node->right),item);
	}
	else
	{
		return search(node->left,item);
	}
	
}
struct node* inorder_traversal(struct node* node)
{
	if(node!=NULL)
	{
		inorder_traversal(node->left);
		cout<<(node->key)<<endl;
		inorder_traversal(node->right);
	}
}
int main()
{
	int value;
	struct node* root = NULL;
	cout<<"Enter the value that you want to insert in the beginning\n";
	cin>>value;
	char ch;
	root = insertnode(root,value);
	while(1)
	{
		cout<<"Press 1 to insert a value in the Binary Search Tree\n"<<"Press 2 to check the inorder traversal of the tree\n"<<"Press 3 to search a value in the tree\n"<<"Press 4 to exit\n";
		cin>>ch;
		if(ch=='1')
		{
			int value2;
			cout<<"Enter the value that you want to insert\n";
			cin>>value2;
			insertnode(root,value2);
		}
		else if(ch=='2')
		{
			cout<<"The inorder traversal of the Tree is:\n";
			inorder_traversal(root);
		}
		else if(ch=='3')
		{
			int value3;
			cout<<"Enter the value that you want to search\n";
			cin>>value3;
			if(search(root,value3))
			{
			cout<<"Present\n";
		    }
			else
			cout<<"Not Present\n";
		}
		else
		{
			break;
		}
	}
	return 0;
}
