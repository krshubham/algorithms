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


void transpose(vector<vector<ll>>&v,ll r,ll c)
{
	ll k = -1;
	for (int i=0;i<r;i++){
		k++;
		for (int j=0;j<k;j++){
			swap(v[i][j],v[j][i]);
		}
	}
}

void reverse(vector<vector<ll>>&v,ll r,ll c)
{
	for (int i=0;i<r/2;i++){
		for (int j=0;j<c;j++){
			swap(v[i][j],v[r-i-1][j]);
		}
	}
}

int main()
{
	ll r,c,x;
	cin>>r>>c;
	vector<vector<ll>>v(r);

	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			cin>>x;
			v[i].pb(x);
		}
	}
	transpose(v,r,c);
	reverse(v,r,c);
	transpose(v,r,c);
	reverse(v,r,c);
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}

}
