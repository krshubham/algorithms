#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int arr1[n];
	int arr2[m];
	string x;
	for (int i=1;i<=n;i++)
		cin>>arr1[i];
	for (int i=1;i<=m;i++)
		cin>>arr2[i];

	int a[n+1][m+1];
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			if (i == 0 || j == 0)
				a[i][j] = 0;

			else if (arr1[i] == arr2[j])
				a[i][j] = a[i-1][j-1]+1;

			else
				a[i][j] = max(a[i-1][j],a[i][j-1]);	 
		}
	}
	//cout<<a[n][m]<<" ";
	/*for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int k =0;
	int i = n;
	int j = m;
	int index = a[n][m];
	int res[a[n][m]-1];
	while(1)
	{
		/*cout<<"arr1[i]= "<<arr1[i]<<endl;
		cout<<"arr2[j]= "<<arr2[j]<<endl;*/
		if (i<=0 || j<=0)
			break;
		if (arr1[i] == arr2[j])
		{
			res[--index] = arr1[i];
			i--;
			j--;
			k++;
		}

		else if (a[i-1][j]>a[i][j-1])
			i--;
		else
			j--;
	}
	for (int i=0;i<k;i++)
		cout<<res[i]<<" ";

}