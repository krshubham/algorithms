#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

string eval(vector<char>&v1){
	ll f,k;
	for (int i=0;i<v1.size();i++){
		if (v1[i] == ')'){
			for (int j=i-1;j>=0;j--){
				if (v1[j] == '('){
					f = j;
					k = i;
					break;
				}
			}
			if (v1[f-1] == '-' && f != 0){
				for (int j=f+1;j<k;j++){
					if (v1[j] == '-')
						v1[j] = '+';
					else if (v1[j] == '+')
						v1[j] = '-';
				}
			}

			v1.erase(v1.begin()+f,v1.begin()+f+1);
			v1.erase(v1.begin()+k-1,v1.begin()+k);
			i -= 2;
		}
	}
	string x;
	for (int i=0;i<v1.size();i++)
		x += v1[i];
	return x;
}

bool cmp(string a,string b){
	vector<pair<ll,ll>>v1(26,pair<ll,ll>(0,0));
	vector<pair<ll,ll>>v2(26,pair<ll,ll>(0,0));

	if (a[0] != '+' && a[0] != '-')
		v1[a[0]-'a'].first++;
	ll len = a.size();
	for (int i=1;i<len;i++){
		if (a[i] != '+' && a[i] != '-'){
			if (a[i-1] == '+'){
				if (v1[a[i]-'a'].second != 0)
					v1[a[i]-'a'].second--;
				else
					v1[a[i]-'a'].first++;
			}
			else if (a[i-1] == '-'){
				if (v1[a[i]-'a'].first != 0)
					v1[a[i]-'a'].first--;
				else
					v1[a[i]-'a'].second++;
			}
		}
	}

	len = b.size();
	if (b[0] != '+' && b[0] != '-')
		v2[b[0]-'a'].first++;

	for (int i=1;i<len;i++){
		if (b[i] != '+' && b[i] != '-'){
			if (b[i-1] == '+'){
				if (v2[b[i]-'a'].second != 0)
					v2[b[i]-'a'].second--;
				else
					v2[b[i]-'a'].first++;
			}
			else if (b[i-1] == '-'){
				if (v2[b[i]-'a'].first != 0)
					v2[b[i]-'a'].first--;
				else
					v2[b[i]-'a'].second++;
			}
		}
	}

	for (int i=0;i<26;i++){
		if ((v1[i].first != v2[i].first)||(v1[i].second != v2[i].second))
			return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string x,y,a,b;
		cin>>x>>y;

		ll len = x.size();

		vector<char>v1;
		vector<char>v2;

		for (int i=0;i<len;i++)
			v1.pb(x[i]);

		len = y.size();
		for (int i=0;i<len;i++)
			v2.pb(y[i]);

		a = eval(v1);
		b = eval(v2);
		if (cmp(a,b))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}	
}
