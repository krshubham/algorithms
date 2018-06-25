bool isIdentical(Node *node1, Node *node2)
{
    if ((node1->left == NULL && node1->right == NULL) && (node2->left != NULL || node2->right != NULL))
        return 0;
    else if ((node2->left == NULL && node2->right == NULL) && (node1->left != NULL || node1->right != NULL))
        return 0;
    else if ((node1->left == NULL && node1->right == NULL) && (node2->left == NULL && node2->right == NULL)){
        if (node1->data == node2->data)
            return 1;
        else
            return 0;
    }
    bool x=1,y=1,z=1;
    if ((node1->left != NULL && node2->left == NULL) || (node1->left == NULL && node2->left != NULL))
        x = 0;
    else if (node1->left != NULL && node2->left != NULL)
        x = isIdentical(node1->left,node2->left);
    
    if ((node1->right != NULL && node2->right == NULL) || (node1->right == NULL && node2->right != NULL))
        y = 0;
    else if (node1->right != NULL && node2->right != NULL)
        y = isIdentical(node1->right,node2->right);
    
    if (node1->data != node2->data)
        z = 0;
    return x&y&z;
    
}