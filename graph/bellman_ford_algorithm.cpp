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
	vector<pair<ll,ll>>v1[n];
	vector<pair<ll,ll>>::iterator it1;
	for (int i=0;i<e;i++){
		cin>>x>>y>>z;
		v1[x].pb(mp(y,z));
	}
	ll k[n];
	ll p[n];
	fill(k,k+n,INT_MAX);
	fill(p,p+n,-1);
	k[0] = 0;
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n;j++){
			for (it1=v1[j].begin();it1!=v1[j].end();it1++){
				x = it1->first;
				y = it1->second;
				if (k[x]>k[j]+y){
					k[x] = k[j]+y;
					p[x] = j;
				}
			}
		}
	}
	ll t[n];
	for (int i=0;i<n;i++)
		t[i] = k[i];
	for (int i=0;i<n;i++)
		cout<<k[i]<<" ";
	cout<<endl;
	for (int j=0;j<n;j++){
		for (it1=v1[j].begin();it1!=v1[j].end();it1++){
			x = it1->first;
			y = it1->second;
			if (k[x]>k[j]+y){
				k[x] = k[j]+y;
				p[x] = j;
			}
		}
	}
	for (int i=0;i<n;i++){
		if (t[i]<k[i]){
			cout<<"Graph Contains The Negative Cycles"<<endl;
			return 0;
		}
	}
	cout<<"Graph Does Not Contain The Negative Cycle"<<endl;

	/*for (int i=0;i<n;i++){
		cout<<k[i]<<" ";		
	}
	cout<<endl;
	for (int i=0;i<n;i++)
		cout<<p[i]<<" ";*/
}

