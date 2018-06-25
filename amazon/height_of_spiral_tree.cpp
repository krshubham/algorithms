int findTreeHeight(Node* node)
{
    if ((node->left != NULL && node->left->right != NULL && node->left->right == node) || (node->left == NULL && node->right == NULL))
        return 1;
    int lvalue = 0;
    int rvalue = 0;
    if (node->left != NULL)
        lvalue = 1+findTreeHeight(node->left);
    if (node->right != NULL)
        rvalue = 1+findTreeHeight(node->right);
    
    return max(lvalue,rvalue);
}