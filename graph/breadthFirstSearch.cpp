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
#include <queue>
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
void bfs(int m,queue<int> &q1,vector<int>*v1,int *visited){
	vector<int> :: iterator it1;
	for (it1 = v1[m].begin();it1 != v1[m].end();it1++){
		if (visited[*it1] == 0){
			q1.push(*it1);
			visited[*it1] = 1;			
		}

	}
}

int main(){
	int v,x,y,m,n;
	cin>>v;
	vector<int>v1[v];
	vector<int> :: iterator it1;
	queue<int> q1;
	int visited[v];
	for (int i=0;i<v;i++)
		visited[i] = 0;
	for (int i=0;i<v;i++){
		cin>>x>>y;
		v1[x].push_back(y);
	}
	


	for (int i=0;i<v;i++){
		if (visited[i] == 0){
			visited[i] = 1;
			q1.push(i);
		}
		while(!q1.empty()){
			m = q1.front();
			//visited[m] = 1;
			bfs(m,q1,v1,visited);
			q1.pop();
		}
	}
}