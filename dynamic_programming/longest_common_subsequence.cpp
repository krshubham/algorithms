// here we will try and implement the concept of longest common subsequence
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x,y;
	cin>>x>>y;
	int len1,len2;
	len1 = x.size();
	len2 = y.size();
	int arr[len1+1][len2+1];
	for (int i=0;i<=len1;i++)
	{
		for (int j=0;j<=len2;j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (x[i] == y[j])
				arr[i][j] = 1 + arr[i-1][j-1];
			else
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]); 
		}
	}
	cout<<"The Required Length Of The subsequence is  "<<arr[len1][len2]<<endl;
}