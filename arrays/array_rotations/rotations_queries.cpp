#include <bits/stdc++.h>
long long totalchocolates(vector < int > input1)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for (int i=0;i<input1.size();i++){
        pq.push(input1[i]);
    }
    int x,y,z,a,b,c;
    int ans = 0;
    int t;
    while(!pq.empty()){
        x = pq.top();
        pq.pop();
        if (pq.size() == 0){
            if (x<=1000)
                ans += x;
            break;
        }
        if (x<=1000){
            t = x/2;
            ans += t;
        }
        y = pq.top();
        pq.pop();
        y += x-t;
        pq.push(y);
        
        
        
    
    }
    return ans;
}

int main() {
    int output;
    int ip1_size = 0;
    cin >> ip1_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> ip1;
    int ip1_item;
    for(int ip1_i=0; ip1_i<ip1_size; ip1_i++) {
        cin >> ip1_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        ip1.push_back(ip1_item);
    }
    output = totalchocolates(ip1);
    cout << output << endl;
    return 0;
}

    
    
        
}