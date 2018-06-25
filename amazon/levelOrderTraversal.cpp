int get_height(Node *node){
    if (node->left == NULL && node->right == NULL)
        return 0;
    int lchild = 0;
    int rchild = 0;
    
    if (node->left != NULL)
        lchild = 1+get_height(node->left);
    
    if (node->right != NULL)
        rchild = 1+get_height(node->right);
    return max(lchild,rchild);
}

void levelOrder_utilization(Node *node,int cnt){
    if (cnt == 0){
        cout<<node->data<<" ";
        return;
    }
    if (cnt>0){
        if (node->left != NULL)
            levelOrder_utilization(node->left,cnt-1);
        if (node->right != NULL)
            levelOrder_utilization(node->right,cnt-1);
    }
}

void levelOrder(Node* node)
{
  int height = get_height(node);
  for (int i=0;i<=height;i++)
        levelOrder_utilization(node,i);
  
}
