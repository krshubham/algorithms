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
	int t;
	cin>>t;
	while(t--){
		string x,res;
		ll k;
		cin>>x>>k;
		ll len = x.size();
		if (len == k){
			cout<<0<<endl;
			continue;
		}
		ll a = 0;
		ll temp =0,m=0,t,f=-1;
		ll z = 0;
		l1:for (int i=a;i<=a+k;i++){
			temp = x[i]-'0';
			//cout<<"temp= "<<temp<<endl;
			if (temp>m){
				m = temp;
				t = i;
			}
		}
		//cout<<"m= "<<m<<endl;
		res += m+'0';
		z++;
		k = k-(t-f-1);
		//cout<<"k= "<<k<<endl;
		f = t;
		a = t+1;
		m = 0;
		if (k>=len-a)
			goto l2;
		else if (k>0)
			goto l1;

		for (int i=a;i<len;i++)
			res += x[i];

		l2:cout<<res<<endl;

	}
}