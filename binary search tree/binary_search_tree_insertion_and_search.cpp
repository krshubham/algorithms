#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

struct node{
	int key;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = data;
	temp->left = NULL;
	temp->right = NULL;
}

struct node *insert(struct node *node,int data){
	if (node==NULL){
		return newnode(data);
	}

	if (node->key<data){
		node->right = insert(node->right,data);
	}
	else if (node->key>data){
		node->left = insert(node->left,data);
	}
	return node;
}

void inorder(struct node *root){

	if (root != NULL){
		inorder(root->left);
		cout<<root->key<<endl;
		inorder(root->right);
	}
}


int main(){
	struct node *root = NULL;
	struct node *root2 = NULL;
	root = insert(root,50);
	insert(root,30);
	insert(root,40);
	insert(root,10);
	insert(root,35);
	insert(root,60);
	inorder(root);
	
}
