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
void all_topological_sort(vector<ll>*v1,ll *ind,ll *v,vector<ll>&res,ll n){
	vector<ll>::iterator it1;
	bool flag = false;
	for (int i=0;i<n;i++){
		if (v[i]==0 &&ind[i]==0){
			v[i]=1;
			res.pb(i);
			for (it1=v1[i].begin();it1!=v1[i].end();it1++)
				ind[*it1]--;
			all_topological_sort(v1,ind,v,res,n);
			flag = true;
			v[i]=0;
			res.erase(res.end()-1);
			for (it1=v1[i].begin();it1!=v1[i].end();it1++)
				ind[*it1]++;
		}
	}
	if (!flag){
		for (int i=0;i<n;i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}
}

int main(){
	ll n,e,x,y,z;
	cin>>n>>e;
	vector<ll>res;
	vector<ll>v1[n];
	ll v[n];
	ll ind[n];
	fill(v,v+n,0);
	fill(ind,ind+n,0);
	for (int i=0;i<e;i++){
		cin>>x>>y;
		v1[x].pb(y);
		ind[y]++;
	}
	all_topological_sort(v1,ind,v,res,n);

}
