#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
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
ll pivot = -1;
ll ans = 0;
int bin_search(ll *arr,ll l,ll h,ll x)
{
	/*cout<<"l ="<<l<<endl;
	cout<<"h= "<<h<<endl;*/
	if (l == h)
	{
		if (arr[l] == x)
			return l;
		else
			return -1;
	}
	ll m = (l+h)/2;
	if (arr[m] == x)
		return m;
	else if (arr[m]>x)
		bin_search(arr,l,m,x);
	else
		bin_search(arr,m+1,h,x);
}

void find_piv(ll *arr,ll l,ll h)
{

	if (l == h)
		return;
	ll m = (l+h)/2;
	if (arr[m-1]>arr[m] && arr[m+1]>arr[m])
		pivot = m;
	else if (arr[m]>arr[0])
		find_piv(arr,m+1,h);
	else
		find_piv(arr,l,m); 
}

void find_ele(ll *arr,ll piv,ll n,ll x)
{
	if (piv == 0){
		ans = bin_search(arr,0,n-2,x);
		return;		
	}
	else if (piv == n-1){
		ans = bin_search(arr,1,n-1,x);
		return;
	}
	else{
		ans = bin_search(arr,0,pivot,x);
		if (ans == -1)
			ans = bin_search(arr,pivot,n-1,x);
	}


}
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	find_piv(arr,0,n-1);
	if (pivot == -1)
		pivot = min(arr[0],arr[n-1]);
	//cout<<pivot<<endl;
	ll x;
	cin>>x;
	find_ele(arr,pivot,n,x);
	cout<<ans<<endl;


}