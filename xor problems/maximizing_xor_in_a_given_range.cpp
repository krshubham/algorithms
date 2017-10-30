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
    ll x,y;
    cin>>x>>y;
    ll z = x^y;
    ll c = 0;
    while(z != 0)
    {
        c++;
        z >>= 1;
    }
    ll sum = 0;
    ll m = 1;
    while(c != 0)
    {
        sum += m;
        m <<= 1;
        c--;
    }
    cout<<sum<<endl; 
}