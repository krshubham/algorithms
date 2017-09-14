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
int range_min_query(int *segtree,int qlow,int qhigh,int low,int high,int pos){
	if (qlow<=low && qhigh>=high)
		return segtree[pos];
	else if (qlow>high || qhigh<low)
		return INT_MAX;
	int mid = (low+high)/2;

	int x = range_min_query(segtree,qlow,qhigh,low,mid,2*pos+1);
	int y = range_min_query(segtree,qlow,qhigh,mid+1,high,2*pos+2);
	
	return min(x,y);
}



int main(){
	int n,qlow,qhigh;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	int x = 4*n;
	int segtree[x];
	for (int i=0;i<x;i++)
		segtree[i] = -1;
	construct(arr,segtree,0,n-1,0);

	cin>>qlow>>qhigh;
	int z = range_min_query(segtree,qlow,qhigh,0,n-1,0);
	cout<<"z= "<<z<<endl;
	

	


}