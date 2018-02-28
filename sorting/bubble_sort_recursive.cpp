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
ll n;

void bubble_sort(ll *arr,ll i,ll j){
    if (j == n)
        return;

    if (arr[i]>arr[j])
        swap(arr[i],arr[j]);

    bubble_sort(arr,i,j+1);
    
}

int main(){
    cin>>n;
    ll arr[n];

    for (int i=0;i<n;i++)
        cin>>arr[i];

    for (int i=0;i<n;i++){
        bubble_sort(arr,i,i+1);
    }

    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
