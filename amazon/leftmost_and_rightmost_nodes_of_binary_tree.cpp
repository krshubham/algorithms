
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Function to print corner node at each level */
int get_height(Node *node){
    if (node->left == NULL && node->right == NULL)
        return 0;
    int lcount = 0;
    int rcount = 0;
    
    if (node->left != NULL)
        lcount = 1+get_height(node->left);
    if (node->right != NULL)
        rcount = 1+get_height(node->right);
    return max(lcount,rcount);
}

void levelordertraversal(Node *node,int cnt,vector<int>&v1){
    if (cnt == 0){
        v1.push_back(node->key);
        return;
    }
    if (cnt>0){
        if (node->left != NULL)
            levelordertraversal(node->left,cnt-1,v1);
        if (node->right != NULL)
            levelordertraversal(node->right,cnt-1,v1);
    }
}

void printCorner(Node *node)
{
    int h = get_height(node);
    cout<<node->key<<" ";
    
    for (int i=1;i<=h;i++){
        vector<int>v1;
        levelordertraversal(node,i,v1);
        if (v1.size() == 1)
            cout<<v1[0]<<" ";
        else if (v1.size() == 0)
            continue;
        else
            cout<<v1[0]<<" "<<v1[v1.size()-1]<<" ";
    }
}