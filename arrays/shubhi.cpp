#include <bits/stdc++.h>
using namespace std;

void merge(int *arr,int l,int m,int h)
{
    int n1 = (m-l+1);
    int n2 = (h-m);
    int a[n1];
    int b[n2];
    for (int i=0;i<n1;i++)
        a[i] = arr[i+l];
    for (int i=0;i<n2;i++)
        b[i] = arr[m+1+i];

    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2)
    {
        if (a[i]>b[j])
        {
            arr[k++] = b[j];
            j++;
        }
        else
        {
            arr[k++] = a[i];
            i++;
        }
    }
    while(i<n1)
    {
        arr[k++] = a[i];
        i++;
    }
    while(j<n2)
    {
        arr[k++] = b[j];
        j++;
    }
}

void inversion_count(int *arr,int l,int m,int h,int &ans)
{
    int n1 = (m-l+1);
    int n2 = (h-m);
    int a[n1];
    int b[n2];
    for (int i=0;i<n1;i++)
        a[i] = arr[l+i];
    for (int i=0;i<n2;i++)
        b[i] = arr[m+1+i];
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2)
    {
        if (a[i]>b[j])
        {
            ans += n1-i;
            j++;            
        }
        else
        {
            i++;
        }
    }
    //cout<<"ans= "<<ans<<endl;
}
void mergesort(int *arr,int l,int h,int &ans)
{
    if (l>=h)
        return;
    int m = (l+h)/2;
    mergesort(arr,l,m,ans);
    mergesort(arr,m+1,h,ans);
    inversion_count(arr,l,m,h,ans);
    merge(arr,l,m,h);
}
int main()
{
    int n,ans=0;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
        cin>>arr[i];
    mergesort(arr,0,n-1,ans);
    cout<<"total number of inversion count is "<<ans<<endl;
}