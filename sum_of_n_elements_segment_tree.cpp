#include <bits/stdc++.h>

void construct(int *arr,int *segtree,int low,int high,int pos){
	if (low == high){
		segtree[pos] = arr[low];
		return;
	}
	int mid = (low+high)/2;
	construct(arr,segtree,low,mid,2*pos+1);
	construct(arr,segtree,mid+1,high,2*pos+2);
	segtree[pos] = segtree[2*pos+1]+segtree[2*pos+2];
}

using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	int segtree[4*n];
	for (int i=0;i<4*n;i++)
		segtree[i] = -1;

	for  (int i=0;i<n;i++)
		cin>>arr[i];

	construct(arr,segtree,0,n-1,0);
	for (int i=0;i<4*n;i++){
		if (segtree[i] != -1){
			cout<<segtree[i]<<" ";
		}
	}
}