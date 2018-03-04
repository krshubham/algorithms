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
	return temp;
}

struct node *insert(struct node *node,int data){
	if (node==NULL)
		return newnode(data);

	if (node->key>data)
		node->left = insert(node->left,data);
	else if (node->key<data)
		node->right = insert(node->right,data);

	return node;
}

struct node *minmax_value(struct node *node){
	node = node->right;
	while(node->left!=NULL)
		node = node->left;
	return(node);
}

struct node *deletenode(struct node *node,int data){
	if (node==NULL)
		return node;

	if (node->key>data)
		node->left = deletenode(node->left,data);
	else if (node->key<data)
		node->right = deletenode(node->right,data);
	else{
		if (node->left == NULL){
			struct node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL){
			struct node *temp = node->left;
			free(node);
			return temp;
		}

		struct node *temp = minmax_value(node);
		node->key = temp->key;
		deletenode(node->right,temp->key);
	}
}

void inorder(struct node *node){
	
	if (node != NULL){
		inorder(node->left);
		cout<<node->key<<" ";
		inorder(node->right);
	}
}


int main(){
	struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout<<endl;
	deletenode(root,20);
	inorder(root);
	cout<<endl;
	deletenode(root,30);
	inorder(root);
	cout<<endl;
	deletenode(root,50);
	inorder(root);
	cout<<endl;

}
