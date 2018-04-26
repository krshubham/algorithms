#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll fact[n+1];
		fact[0] = 1;
		for (int i=1;i<=n;i++)
			fact[i] = fact[i-1]*i;


		ll r,b,g;
		cin>>r>>b>>g;

		ll l = n-(r+b+g);
		ll ans = 0;
		for (int i=0;i<=l;i++){
			for (int j=0;j<=l-i;j++){
				ll  s = l-(i+j);
				ans += fact[n]/(fact[i+r]*fact[j+b]*fact[s+g]);
			}
		}
		cout<<ans<<endl;


	}	
}
