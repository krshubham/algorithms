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

void bfs(vector<ll>*v1,queue<ll>&q,ll *vis,ll x){
	if (vis[x] == 1)
		return;
	vector<ll> :: iterator it1;

	for (it1=v1[x].begin();it1!=v1[x].end();it1++){
		q.push(*it1);
	}
	vis[x] = 1;

}


int main(){
	ll v,e,x,y,z;
	cin>>v>>e;
	vector<ll>v1[v];
	queue<ll>q;

	for (int i=0;i<e;i++){
		cin>>x>>y;
		v1[x].pb(y);
	}
	q.push(2);
	ll vis[v];
	fill(vis,vis+v,0);

	while(!q.empty()){
		x = q.front();
		q.pop();
		bfs(v1,q,vis,x);
	}
}

