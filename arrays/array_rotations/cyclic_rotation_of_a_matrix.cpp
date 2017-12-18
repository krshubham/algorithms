#include <bits/stdc++.h>


void prims_algorithm(int x,int input1,int input2,vector<vector<int>>input3,int* visited,int *parent,int *key,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq){
    if (visited[x] == 1)
        return;
    for (int i=0;i<input2;i++){
        if ((input3[i][0] == x || input3[i][1] == x)){
        
            if (input3[i][0] == x && key[input3[i][1]]>input3[i][2] && visited[input3[i][1]] == 0){
                key[input3[i][1]] = input3[i][2];
                pq.push(make_pair(input3[i][2],input3[i][1]));
            }
            else if (input3[i][1] == x  && key[input3[i][0]]>input3[i][1] && visited[input3[i][0]] == 0)
            {
                key[input3[i][0]] = input3[i][2];
                pq.push(make_pair(input3[i][2],input3[i][0]));
            }
        }   
    }
    visited[x] = 1;
}


int getRoutes(int input1,int input2,vector < vector < int > > input3)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>test;
	pq.push(make_pair(0,1));
	int x,y,z,a,b,c;
	int visited[input1+1],parent[input1+1],key[input1+1];
	fill(visited+1,visited+input1+1,0);
	fill(parent+1,parent+input1+1,-1);
	fill(key+2,key+input1,INT_MAX);
	key[1] = 0;
	while(!pq.empty()){
	    x = pq.top().second;
	    pq.pop();
	    prims_algorithm(x,input1,input2,input3,visited,parent,key,pq);
	}
	int ans = 0;
	for (int i=2;i<=input1;i++){
	    ans += key[i];
	}
	return ans;
}
int main() {
    int output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2;
    cin >> ip2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip3_rows = 0;
    int ip3_cols = 0;
    cin >> ip3_rows >> ip3_cols;
    vector< vector < int > > ip3(ip3_rows);
    for(int ip3_i=0; ip3_i<ip3_rows; ip3_i++) {
        for(int ip3_j=0; ip3_j<ip3_cols; ip3_j++) {
            int ip3_tmp;
            cin >> ip3_tmp;
            ip3[ip3_i].push_back(ip3_tmp);
        }
    }
    output = getRoutes(ip1,ip2,ip3);
    cout << output << endl;
    return 0;
}