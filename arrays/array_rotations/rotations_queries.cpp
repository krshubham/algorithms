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
    ll n,x,y,z,d,e,f,g;
    char a,b,c;
    cin>>n;
    ll arr[n];
    for (int i=0;i<n;i++)
        cin>>arr[i];

    ll temp[2*n];
    fill(temp,temp+2*n,0);
    temp[0] = arr[0];

    for (int i=1;i<n;i++)
        temp[i] = temp[i-1]+arr[i];
    for (int i=n;i<2*n;i++){
        temp[i] = temp[i-1]+arr[i-n];

    }
    /*for (int i=0;i<n;i++)
        temp[i] =  arr[i];
*/
    /*for (int i=0;i<2*n;i++)
        cout<<"temp[i]= "<<temp[i]<<endl;*/
    ll q;
    cin>>q;

    ll index = 0;
    for (int i=0;i<q;i++){
        cin>>x;
        if (x == 1){
            cin>>d;
            d = d%n;
            index = (index-d);
            if (index<0)
                index = n-d;

        }
        else if (x == 2){
            cin>>d;
            d = d%n;
            index = (index+d)%n;
        }
       else{
            cin>>d>>e;
            d = d%n;
            e = e%n;
            d = (d+index)%(2*n);
            e = (e+index)%(2*n);
            /*cout<<index<<endl;
            cout<<e<<endl;
            cout<<d<<endl;*/
            if (d == 0)
                cout<<temp[e]-temp[d]<<endl;
            else
                cout<<temp[e]-temp[d-1]<<endl;
       }
    }
}