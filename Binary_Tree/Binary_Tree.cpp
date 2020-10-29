//following is a recursive approach of Tree Traversals
//1)-Inorder
//2)-PreOrder
//3)-PostOrder
//Not recursive here
//4)- LevelOrder
//5)- Insertion 
//we will not be constructing an entire class for the binary tree, we'll just create the node and construct the tree like that
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int val ;
	Node *left;
	Node *right;
	
	//constructor function for initialisation
	Node(int data) 
    { 
        this->val = data; 
        left = right = NULL; 
    } 
};
void inOrder(Node *temp){
	
	if(temp == NULL){
		return ;
	}
	
	inOrder(temp->left);
	
	cout<<(temp->val)<<" ";
	
	inOrder(temp->right);
}
void preOrder(Node *temp){
	
	if(temp == NULL){
		return;
	}
	
	cout<<(temp->val)<<" ";
	
	preOrder(temp->left);
	
	preOrder(temp->right);
}
void postOrder(Node *temp){
		
	if(temp == NULL){
		return;
	}
	
	postOrder(temp->left);
	
	postOrder(temp->right);
	
	cout<<(temp->val)<<" ";
}

void levelOrder(Node *root){
	queue<Node*>q;
	q.push(root);
	
	while(!q.empty()){
		Node *temp = q.front();
		cout<<temp->val<<" ";
		q.pop();
		
		if(temp->left){
			q.push(temp->left);
		}
		
		if(temp->right){
			q.push(temp->right);
		}
	}
}

void insert(Node *root, int val){
	//doing level order traversal for insertion
	Node *newNode = new Node(val);
	queue<Node*>q;
	q.push(root);
	
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		
		if(!temp->left){
			temp->left = newNode;
			break;
		}else{
			q.push(temp->left);
		}
		
		if(!temp->right){
			temp->right = newNode;
			break;
		}else{
			q.push(temp->right);
		}
	}
}

//iterative code for preOrder Traversal
void preOrderIterative(Node *root){
	stack<Node*>s;
	
	s.push(root);
	
	while(!s.empty()){
		Node *temp = s.top();
		cout<<temp->val<<" ";
		s.pop();
		
		if(temp->right){
			s.push(temp->right);
		}
		
		if(temp->left){
			s.push(temp->left);
		}
	}
}

void inOrderIterative(Node *root){
	stack<Node*>s;
	s.push(root);
	Node *temp;
	int flag = 1;
	
	while(!s.empty()){
		
	if(flag == 1){
		while(s.top()->left){
		temp = s.top()->left;
		s.push(temp); 
	}	
	}
	
	
	if(s.top()->right){
		temp = s.top()->right;
		cout<<s.top()->val<<" ";
		s.pop();
		s.push(temp);
		flag=1;
		
	}else{
		cout<<s.top()->val<<" ";
		s.pop();
		flag = 0;
	}
	}
		
}

//iterative postOrder using 2 stacks
void iterativePostOrderTwoStacks(Node *root){
	stack<Node*>s1,s2;
	
	s1.push(root);
	
	while(!s1.empty()){
		Node *temp = s1.top();
		s2.push(temp);
		s1.pop();
		
		if(s2.top()->left){
			s1.push(s2.top()->left);
		}
		
		if(s2.top()->right){
			s1.push(s2.top()->right);
		}
	}
	while(!s2.empty()){
		cout<<s2.top()->val<<" ";
		s2.pop();
	}
}

//Deletion in a binary Tree
// function to delete the given deepest node (d_node) in binary tree
void deleteDeepest(Node* root, Node* d_node){
	queue<Node*>q;
	q.push(root);
	
	Node* temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		
		if(temp == d_node){
			temp = NULL;
			delete(d_node);
			return;
		}
		
		if(temp->right){
			if(temp->right == d_node){
				temp->right = NULL;
				delete(d_node);
				return;
			}else{
				q.push(temp->right);
			}
		}
		
		if(temp->left){
			if(temp->left == d_node){
				temp->left = NULL;
				delete(d_node);
				return;
			}else{
				q.push(temp->left);
			}
		}
	}
}

//function to delete an element in a binary tree
Node* deletion(Node* root, int val){
	if(root == NULL){
		return NULL;
	}
	
	if(root->left == NULL && root->right == NULL){
		if(root->val == val){
			return NULL;
		}else{
			return root;
		}
	}
	
	queue<Node*>q;
	q.push(root);
	
	Node* temp;
	Node* val_node = NULL;
	
	while(!q.empty()){
		temp = q.front();
		q.pop();
		
		if(temp->val == val){
			val_node = temp;
		}
		
		if(temp->left){
			q.push(temp->left);
		}
		
		if(temp->right){
			q.push(temp->right);
		}
	}
	
	if(val_node != NULL){
		int x = temp->val;
		deleteDeepest(root,temp);
		val_node->val = x;
	}
	return root;
}



int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
//	inOrder(root);
//	cout<<endl;
//	insert(root,6);
//	inOrder(root);
//	cout<<endl;
//	levelOrder(root);
//	cout<<endl;
//	preOrder(root);
//	cout<<endl;
//	postOrder(root);
//	cout<<endl;
//	preOrderIterative(root);
//	inOrderIterative(root);
//	iterativePostOrderTwoStacks(root);
//	iterativePostOrderOneStack(root);
	return 0;
}
