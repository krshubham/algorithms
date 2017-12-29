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

void dfs(vector<pair<ll,ll>>*v1,ll *v,ll *k,ll i){
	vector<pair<ll,ll>>::iterator it1;
	ll a,b;
	for (it1=v1[i].begin();it1!=v1[i].end();it1++){
		a = it1->first;
		b = it1->second;
		if (b+k[i]>k[a])
			k[a] = b+k[i];
		dfs(v1,v,k,it1->first);
		v[it1->first] = 1;
	}	
}

int main(){
	ll n,e,x,y,z;
	cin>>n>>e;
	vector<pair<ll,ll>>v1[n];
	for (int i=0;i<e;i++){
		cin>>x>>y>>z;
		v1[x-1].pb(mp(y-1,z));
	}
	ll v[n];
	fill(v,v+n,0);
	ll k[n];
	fill(k,k+n,INT_MIN);
	k[0] = 0;
	for (int i=0;i<n;i++){
		if (v[i] == 0){
			dfs(v1,v,k,i);
			v[i] = 1;
		}
	}

	for (int i=0;i<n;i++){
		if (k[i] == INT_MIN)
			cout<<"Not reachable from the source vertes"<<" ";
		else 
			cout<<k[i]<<" ";
	}
}

