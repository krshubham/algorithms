void level(Node *node,map<ll,ll>&m1){
    if (node->left == NULL && node->right == NULL)
        return;
    
    if (node->left != NULL){
        m1[node->left->data] = m1[node->data]-1;
        level(node->left,m1);
    }
    if (node->right != NULL){
        m1[node->right->data] = m1[node->data]+1;
        level(node->right,m1);
    }
}

void verticalOrder(Node *node){
    map<ll,ll>m1;
    map<ll,ll>::iterator it1;
    map<ll,vector<ll>>m2;
    map<ll,vector<ll>>::iterator it2;
    m1[node->data] = 0;
    level(node,m1);
    
    for (it1=m1.begin();it1!=m1.end();it1++)
        m2[it1->second].push_back(it1->first);
    
    for (it2=m2.begin();it2!=m2.end();it2++){
        for (int i=0;i<it2->second.size();i++){
            cout<<it2->second[i]<<" ";
        }
        cout<<'$';
    }
}