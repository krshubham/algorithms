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
		ll arr[n];
		for (int i=0;i<n;i++)
			cin>>arr[i];

		vector<pair<ll,pair<ll,ll>>>v1;
		vector<pair<ll,pair<ll,ll>>>::iterator it1;
		vector<ll>v2;
		vector<ll>::iterator it2;
		ll sum;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				sum = arr[i]+arr[j];
				v1.pb(mp(sum,mp(i,j)));
				v2.pb(sum);
			}
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		/*for (int i=0;i<v1.size();i++){
			cout<<v1[i].first<<" ";
			cout<<v1[i].second.first<<" ";
			cout<<v1[i].second.second<<" ";
			cout<<endl;
		}*/
		ll su,ind,x;
		cin>>su;
		ll temp=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				x = su-(arr[i]+arr[j]);
				it2 = lower_bound(v2.begin(),v2.end(),x);
				ind = it2-v2.begin();
				while(v1[ind].first == x){
					if (v1[ind].second.first != i && v1[ind].second.first != j && v1[ind].second.second != i && v1[ind].second.second != j){
						temp = 1;
						break;
				}
				ind++;
				}
				if (temp==1)
					break;
			}
			if (temp==1)
				break;
		}

		if (temp==1)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}	
}
