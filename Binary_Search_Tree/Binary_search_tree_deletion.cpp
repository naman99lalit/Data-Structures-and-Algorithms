#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};
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
struct node* minvalue(struct node* node)
{
	struct node* minv= node;
	while(minv->left!=NULL)
	{
		minv=(minv->left);
	}
	return minv;
}
struct node* deletenode(struct node *node,int item)
{
	 if(node==NULL)
	 {
	 	return node;
	 }
	 if(item>(node->key))
	 {
	 	node->right=deletenode(node->right,item);
	 }
	 else if(item<(node->key))
	 {
	 	node->left=deletenode(node->left,item);
	 }
	 else
	 {
	 	if(node->right==NULL)
	 	{
	 		struct node* temp;
	 		temp= node->left;
	 		free(node);
	 		return temp;
		}
		else if(node->left==NULL)
		{
			struct node* temp;
			temp=node->right;
			free(node);
			return temp;
		}
		struct node* temp;
		temp= minvalue(node->right);
		node->key=temp->key;
		node->right=deletenode(node->right,temp->key);
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
		cout<<"Press 1 to insert a value in the Binary Search Tree\n"<<"Press 2 to check the inorder traversal of the tree\n"<<"Press 3 to search a value in the tree\n"<<"Press 4 to delete a value from the BST\n"<<"Press 5 to exit\n";
		cin>>ch;
		if(ch=='1')
		{
			int value2;
			cout<<"Enter the value that you want to insert\n";
			cin>>value2;
			root = insertnode(root,value2);
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
		else if(ch=='4')
		{
			int value4;
			cout<<"Enter the value that you want to delete\n";
			cin>>value4;
			root = deletenode(root,value4);
		}
		else
		{
			break;
		}
	}
	return 0;
}
