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


void prims_algorithm(priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>&pq,ll i,vector<pair<ll,ll>>*v1,ll *k,ll *vi){
	if (vi[i] == 1)
		return;
	vector<pair<ll,ll>> :: iterator it1;

	for (it1 = v1[i].begin();it1 != v1[i].end();it1++){
		if (it1->second<k[it1->first] && vi[it1->first] == 0){
			k[it1->first] = it1->second;
			pq.push(mp(k[it1->first],it1->first));
		}
	}
	vi[i] = 1;
}

int main(){
	ll v,e,x,y,z,a,b,c;
	cin>>v>>e;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

	vector<pair<ll,ll>>v1[v];

	for (int i=0;i<e;i++){
		cin>>x>>y>>z;
		v1[x].pb(mp(y,z));
		v1[y].pb(mp(x,z));
	}

	ll vi[v];
	ll k[v];
	k[0] = 0;
	fill(vi,vi+v,0);
	fill(k+1,k+v,INT_MAX);
	pq.push(mp(0,0));

	while (!pq.empty()){
		x = pq.top().second;
		pq.pop();
		prims_algorithm(pq,x,v1,k,vi);
	}

	for (int i=0;i<v;i++)
		cout<<k[i]<<" ";


}
