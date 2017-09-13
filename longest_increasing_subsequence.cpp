#include <bits/stdc++.h>
using namespace std;


int linear_search(int *arr,int m,int n){
	for (int i=0;i<n;i++){
		if (arr[i] == m)
			return i;
	}
}

int main(){
	int n,m,x,y,z,k=0,max,min,temp2,temp3,temp4,count=0;
	cin>>n;
	vector<int>v1;
	vector<int> :: reverse_iterator it1;
	int arr[n];
	int arr2[n];
	int arr3[n];
	fill(arr3,arr3+n,-1);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	arr2[k++] = arr[0];
	max = arr[0];
	min = arr[0];
	
	for (int i=1;i<n;i++){
		//cout<<"max= "<<max<<endl;
		if (arr[i]>max){
			//cout<<"raghav"<<endl;
			max = arr[i];
			arr2[k++] = max;
			z = k-2;
			//cout<<"z= "<<z<<endl;
			temp2 = linear_search(arr,arr2[z],n);
			//cout<<"temp2= "<<temp2<<endl;
			arr3[i] = temp2;
		}
		else if (arr[i]<min){
			min = arr[i];
			arr2[0] = min;
			arr3[i] = -1;
		}
		else if (arr[i]>min && arr[i]<max){
			x = arr[i];
			y = 0;
			while(x>arr2[y]){
				y++;

			}
			if (y == k-1)
				max = arr[i];
			arr2[y] = arr[i];
			y--;
			temp2 = linear_search(arr,arr2[y],n);
			//cout<<"temp2= "<<temp2<<endl;
			arr3[i] = temp2;
		}

	}
	/*for (int i=0;i<n;i++){
		cout<<arr3[i]<<" ";	
	}*/
	int i = arr2[k-1];
	i = linear_search(arr,i,n);
	//cout<<"i= "<<i<<endl;
	while(arr3[i] != -1){
		count++;
		v1.push_back(arr[i]);
		i = arr3[i];
		if (arr3[i] == -1){
			cout<<arr[i]<<" ";

		}
	}
	if (count == 0)
		cout<<arr[0]<<" ";
	else{
		for (it1 = v1.rbegin();it1 != v1.rend();it1++){
		cout<<*it1<<" ";
		}
	}
	//cout<<arr[temp];

	
	

}