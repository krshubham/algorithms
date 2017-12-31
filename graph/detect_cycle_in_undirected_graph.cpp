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
ll t = 0;
void dfs(vector<ll>*v1,ll *v,ll *p,ll i){
	if (t==1)
		return;
	vector<ll>::iterator it1;
	for (it1=v1[i].begin();it1!=v1[i].end();it1++){
		if (t==1)
			return;
		if (v[*it1]==0){
			v[*it1] = 1;
			p[*it1] = i;
			dfs(v1,v,p,*it1);
		}
		else if (v[*it1]==1 && p[i]!=*it1){
			cout<<"Cycle Exists"<<endl;
			t = 1;
			return;
		}
	}
}

int main(){
	ll n,e,x,y,z;
	cin>>n>>e;
	vector<ll>v1[n];

	for (int i=0;i<e;i++){
		cin>>x>>y;
		v1[x].pb(y);
		v1[y].pb(x);
	}

	ll v[n];
	fill(v,v+n,0);
	ll p[n];
	fill(p,p+n,-1);

	for (int i=0;i<n;i++){
		if (v[i]==0){
			v[i]=1;
			p[i]=-1;
			dfs(v1,v,p,i);
		}
	}
	if (t==0)
		cout<<"cycle does not exist"<<endl;
}

