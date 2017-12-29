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

int main(){
	ll n,e,x,y,z;
	cin>>n>>e;
	vector<ll>v1[n];
	vector<ll>::iterator it1;
	for (int i=0;i<e;i++){
		cin>>x>>y;
		v1[x].pb(y);
		v1[y].pb(x);
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	ll t[n];
	ll v[n];
	fill(t,t+n,-1);
	fill(v,v+n,0);
	for (int i=0;i<n;i++){
		pq.push(mp(v1[i].size(),i));
		t[i] = v1[i].size();
	}
	ll k;
	cin>>k;

	while(!pq.empty()){
		x = pq.top().first;
		y = pq.top().second;
		pq.pop();
		if (x<k && v[y] == 0){
			for (it1=v1[y].begin();it1!=v1[y].end();it1++){
				t[*it1]--;
				pq.push(mp(t[*it1],*it1));
			}
		}
		else if (x>=k)
			break;
		v[y] = 1;
		

	}

	for (int i=0;i<n;i++)
		cout<<t[i]<<" ";

}

