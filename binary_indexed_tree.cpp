#include <iostream>
using namespace std;

void update(int m,int i,int *bit,int n){
	i = i+1;
	while(i<=n){
		bit[i] += m;
		i += i & (-i); 
	}
}
int getsum(int i,int *bit){
	i = i+1;
	int sum = 0;
	while(i>0){
		sum += bit[i];
		i -= i & (-i);
	}
	return sum;
}

int main(){
	int n,x,y,res;
	cin>>n;
	int arr[n];
	int bit[n+1];
	fill(bit,bit+n+1,0);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	for (int i=0;i<n;i++){
		update(arr[i],i,bit,n);
	}
	cout<<"Enter The Element To which you Need To calculate the sum"<<endl;
	cin>>x;
	res = getsum(x,bit);
	cout<<"required sum is "<<res<<endl;

	/*for (int i=0;i<=n;i++)
		cout<<bit[i]<<" ";*/
}