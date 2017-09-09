#include <bits/stdc++.h>
using namespace std;

void construct(int *arr,int *segtree,int low,int high,int pos){
	if (low == high){
		segtree[pos] = arr[low];
		return;
	}
	int mid = (low+high)/2;
	construct(arr,segtree,low,mid,2*pos+1);
	construct(arr,segtree,mid+1,high,2*pos+2);
	segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);

}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	int x = 4*n;
	int segtree[x];
	for (int i=0;i<x;i++)
		segtree[i] = -1;
	construct(arr,segtree,0,n-1,0);

	for (int i=0;i<x;i++){
		if (segtree[i] != -1){
			cout<<"segtree[i]= "<<segtree[i]<<endl;
		}
	}

	


}