#include <bits/stdc++.h>
using namespace std;

void build(unsigned long long *a,unsigned long long *segtree,unsigned long long low,unsigned long long high,unsigned long long pos)
{
    if (low == high)
    {
        segtree[pos] = a[low];
        return;
    }
    unsigned long long mid = (low+high)/2;
    build(a,segtree,low,mid,2*pos+1);
    build(a,segtree,mid+1,high,2*pos+2);
    segtree[pos] = segtree[2*pos+1]+segtree[2*pos+2];


}
// again trying 
void query(unsigned long long *segtree,unsigned long long *lazy,unsigned long long x,unsigned long long y,unsigned long long low,unsigned long long high,unsigned long long pos)
{
    unsigned long long diff;
    if (lazy[pos] != 0)
    {
        diff = lazy[pos];
        lazy[pos] = 0;
        segtree[pos] += diff;
        if (low != high)
        {
            lazy[2*pos+1] += diff;
            lazy[2*pos+2] += diff;
        }
    }
    // no overlap condition
    if (x>high || y<low)
        return;
    else if (x<=low && y>=high)// total overlap condition
    {
        segtree[pos]++;
        if (low !=high)
        {
            lazy[2*pos+1]++;
            lazy[2*pos+2]++;
        }
        return;
    }
    unsigned long long mid = (low+high)/2;
    query(segtree,lazy,x,y,low,mid,2*pos+1);
    query(segtree,lazy,x,y,mid+1,high,2*pos+2);

}

void update(unsigned long long *segtree,unsigned long long *lazy,unsigned long long low,unsigned long long high,unsigned long long pos)
{
    unsigned long long diff;
    if (lazy[pos] != 0)
    {
        diff = lazy[pos];
        lazy[pos] = 0;
        segtree[pos] += diff;
        if (low != high)
        {
            lazy[2*pos+1] += diff;
            lazy[2*pos+2] += diff;
        }
    }
    if (low == high)
        return;
    unsigned long long mid = (low+high)/2;
    update(segtree,lazy,low,mid,2*pos+1);
    update(segtree,lazy,mid+1,high,2*pos+2);
}

void array_build(unsigned long long *b,unsigned long long *segtree,unsigned long long &m,unsigned long long low,unsigned long long high,unsigned long long pos)
{
    if (low == high)
    {
        b[m++] = segtree[pos];
        return;
    }
   unsigned long long mid = (low+high)/2;
   array_build(b,segtree,m,low,mid,2*pos+1);
   array_build(b,segtree,m,mid+1,high,2*pos+2); 
    
}

int main()
{
    unsigned long long n,q,x,y;
    unsigned long long m = 0;
    cin>>n>>q;
    if (n == 1)
    {
        cout<<n*q<<endl;
        return 0;
    }
    
    unsigned long long arr[n];
    unsigned long long segtree[4*n];
    unsigned long long lazy[4*n];
    unsigned long long a[n];
    unsigned long long b[4*n];
    fill(b,b+(4*n),0);
    fill(a,a+n,0);
    fill(segtree,segtree+(4*n),0);
    fill(lazy,lazy+(4*n),0);
    build(a,segtree,0,n-1,0);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    for (int i=0;i<q;i++)
    {
        cin>>x>>y;
        query(segtree,lazy,x-1,y-1,0,n-1,0);
        /*for (int i=0;i<(4*n);i++)
            cout<<segtree[i]<<" ";
        cout<<endl;
        for (int i=0;i<(4*n);i++)
            cout<<lazy[i]<<" ";*/

    }
    update(segtree,lazy,0,n-1,0);    
    /*for (int i=0;i<(4*n);i++)
        cout<<segtree[i]<<" ";
    cout<<endl;
    for (int i=0;i<(4*n);i++)
        cout<<lazy[i]<<" ";*/
    array_build(b,segtree,m,0,n-1,0);
    /*for (int i=0;i<m;i++)
        cout<<b[i]<<" ";*/
    sort(arr,arr+n);
    sort(b,b+n);
    int sum = 0;
    for (int i=0;i<n;i++)
    {
        sum += b[i]*arr[i];
    }
    cout<<sum<<endl;
    
}