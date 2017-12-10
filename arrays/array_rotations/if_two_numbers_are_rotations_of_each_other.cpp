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
ll arr[1000000];

string bin(ll a){
	string x;
	ll k =0;
	while(a !=0){
		if (a%2 == 1){
			arr[k++] = '1';			
		}
		else
			arr[k++] = '0';
		a >>= 1;
	}
	for (int i=k-1;i>=0;i--)
		x += arr[i];
	return x;
}

int main(){
	ll a,b;
	cin>>a>>b;
	string x,y,z;
	x = bin(a);
	y = bin(b);
	/*cout<<"x= "<<x<<endl;
	cout<<"y= "<<y<<endl;*/
	if (a>b){
		z = x+x;
		ll i = z.find(y);
		if (i == -1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;			
	}
	else{
		z = y+y;
		ll i = z.find(x);
		if (i == -1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;	
	}
	
	
	
	

}
