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

int main(int argc, char const *argv[])
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

	ll a=0,b=0,t,z;
	ll prev;
	while(a<r/2 && b<c/2){
		

		z = v[a+1][b];
		t = v[a][b];
		for (int j=b+1;j<c-b;j++){
			x = v[a][j];
			v[a][j] = t;
			t = x;
		}

		for (int i=a+1;i<r-a;i++){
			//cout<<"t= "<<t<<endl;
			x = v[i][c-b-1];
			v[i][c-b-1] = t;
			t = x;
		}
		for (int j = c-b-2;j>=b;j--){
			x = v[r-a-1][j];
			v[r-a-1][j] = t;
			t = x;
		}
		//cout<<"t= "<<t<<endl;
		for (int i = r-a-2;i>=a;i--){
			x = v[i][b];
			v[i][b] = t;
			t = x;
		}
		v[a][b] = z;
		
		
	a++;
	b++;



	}
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

