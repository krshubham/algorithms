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

int main()
{
	ll n,x,y,z;
	cin>>n;
	ll arr[n];
	ll a[n];
	ll b[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];

	a[0] = arr[0];
	for (int i=1;i<n;i++)
		a[i] = min(arr[i],a[i-1]);
	b[n-1] = arr[n-1];

	for (int i=n-2;i>=0;i--)
		b[i] = max(arr[i],b[i+1]);

	ll i=0,j=0,diff=-1;
	while(i<n && j<n)
	{
		if (a[i]>=b[j])
			i++;
		else
		{
			if ((j-i)>diff)
				diff = j-i;
			j++;

		}
	}
	cout<<diff<<endl;		
}