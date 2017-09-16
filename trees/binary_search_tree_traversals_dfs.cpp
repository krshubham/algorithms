#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newnode(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
} 



struct node* insert(struct node *node,int data){
	if (node == NULL)
		node = newnode(data);
	else{
		//cout<<"node->data= "<<node->data<<endl;
		if (node->data>data)
			node->left = insert(node->left,data);
		else if (node->data<data)
			node->right = insert(node->right,data);
	}
	return node;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout <<root->data<<endl;
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
	if (root != NULL)
	{
		cout<<root->data<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<endl;
	}
}


int main(){
	int n,x;
	cin>>n;
	int arr[n];
	struct node *root = NULL;
	for (int i=0;i<n;i++){
		cin>>x;
		root = insert(root,x);
	}
	inorder(root);
	preorder(root);
	postorder(root);

}