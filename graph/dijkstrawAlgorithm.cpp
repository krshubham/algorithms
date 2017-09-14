#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
	if (n <= 1)  {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}
	
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

inline int binSearch(int arr[],int val,int b){
    int low=0,high=b-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>val){
            high=mid-1;
        }
        else if(arr[mid]<val){
            low=mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

void dijkstraw_algorithm(int *visited,int *parent,int *key,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq,vector<pair<int,int>>*v1,int i){
	vector<pair<int,int>> :: iterator it1;
	int k,weight;
	for (it1 = v1[i].begin();it1 != v1[i].end();it1++){
		k = (*it1).first;
		weight = (*it1).second;
		weight += key[i];
		if (visited[k] == 0 && weight<key[k]){
			parent[k] = i;
			key[k] = weight;
			pq.push(make_pair(key[k],k));
		}
	}
}

int main(){
	//cout<<"raghav"<<endl;
	int v,e,x,y,z,m,n;
	cin>>v>>e;
	vector<pair<int,int>>v1[v];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for (int i=0;i<e;i++){
		cin>>x>>y>>z;
		v1[x].push_back(make_pair(y,z));
		v1[y].push_back(make_pair(x,z));
	}
	int parent[v];
	int visited[v];
	int key[v];
	key[0] = 0;
	for (int i=1;i<v;i++)
		parent[i] = -1;
	for (int i=1;i<v;i++)
		key[i] =INT_MAX;
	for (int i=0;i<v;i++)
		visited[i] = 0;

	pq.push(make_pair(0,0));

	while (!pq.empty()){
		m = pq.top().second;
		visited[m] = 0;
		dijkstraw_algorithm(visited,parent,key,pq,v1,m);
		pq.pop();
	}
	for (int i=0;i<v;i++)
		cout<<key[i]<<endl;

}