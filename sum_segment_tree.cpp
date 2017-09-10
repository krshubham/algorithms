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
	segtree[pos] = segtree[2*pos+1]+segtree[2*pos+2];
}

void get_sum(int *segtree,int qlow,int qhigh,int low,int high,int pos,int &sum){
	if (qlow<=low && qhigh>=high){
		sum += segtree[pos];
		return;		
	}
	else if (qlow>high || qhigh<low){
		return;
	}

	int mid = (low+high)/2;
	get_sum(segtree,qlow,qhigh,low,mid,2*pos+1,sum);
	get_sum(segtree,qlow,qhigh,mid+1,high,2*pos+2,sum);


}


int main(){
	int n,qlow,qhigh,sum=0;
	cin>>n;
	int arr[n];
	int segtree[4*n];
	for (int i=0;i<4*n;i++)
		segtree[i] = -1;

	for  (int i=0;i<n;i++)
		cin>>arr[i];

	construct(arr,segtree,0,n-1,0);
	cin>>qlow>>qhigh;

	get_sum(segtree,qlow,qhigh,0,n-1,0,sum);
	cout<<"sum = "<<sum<<endl;
	/*for (int i=0;i<4*n;i++){
		if (segtree[i] != -1){
			cout<<segtree[i]<<" ";
		}
	}*/
}