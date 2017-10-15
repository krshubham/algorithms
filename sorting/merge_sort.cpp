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
void mergesort(int *arr,int l,int h)
{
    if (l>=h)
        return;
    int m = (l+h)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,h);
    merge(arr,l,m,h);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
        cin>>arr[i];
    mergesort(arr,0,n-1);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}