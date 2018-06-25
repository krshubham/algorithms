
void topological_utilization(map<char,vector<char> >m1,int *v,string &res,char x){
    vector<char>v1;
    v1 = m1[x];
    int ind;
    for (int i=0;i<v1.size();i++){
        ind = v1[i]-'a';
        if (v[ind] == 0){
            v[ind] = 1;
            topological_utilization(m1,v,res,v1[i]);
        }
    }
    res += x;
}

void topological_sort(map<char,vector<char> >m1,int *v,int *cnt,string &res){
    char x;
    for (int i=0;i<26;i++){
        if (cnt[i] == 1 && v[i] == 0){
            v[i] = 1;
            x = i+'a';
            topological_utilization(m1,v,res,x);
        }
    }
}

string printOrder(string dict[], int N, int k)
{
    int len1,len2,temp;
    string x,y,res;
    map<char,vector<char> >m1;
    map<char,vector<char> > :: iterator it1;

    for (int i=0;i<N-1;i++){
        x = dict[i];
        y = dict[i+1];
        len1 = x.size();
        len2 = y.size();
        temp = min(len1,len2);
        vector<char>v1;
        bool f = 0;
        for (int j=0;j<temp;j++){
            if (x[j] != y[j]){
                v1 = m1[x[j]];
                for (int k=0;k<v1.size();k++){
                    if (v1[k] == y[j]){
                        f = 1;
                        break;
                    }
                }
                
                if (!f){
                    m1[x[j]].push_back(y[j]);
                    break;
                }
            }
        }
    }
    int cnt[26];
    for (int i=0;i<26;i++)
        cnt[i] = 0;
    int v[26];
    for (int i=0;i<26;i++)
        v[i] = 0;
    
    for (it1 = m1.begin();it1 != m1.end();it1++)
        cnt[it1->first-'a']++;
    topological_sort(m1,v,cnt,res);
    reverse(res.begin(),res.end());
    return res;
}