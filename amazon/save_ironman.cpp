#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main(){
	int t;
	cin>>t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while(t--){
		string x,y,z;
		getline(cin,x);
		ll len = x.size();

		for (int i=0;i<len;i++){
			if (x[i] >= 'a' && x[i] <= 'z')
				y += x[i];
			else if (x[i]>='A' && x[i] <= 'Z'){
				x[i] = x[i]+32;
				y += x[i];
			}
			else if (x[i] >= '1' && x[i] <= '9')
				y += x[i];
		}
		z = y;
		reverse(z.begin(),z.end());
		if (z==y)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}	
}
