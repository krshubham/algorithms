int main()
{
    ll a=0,b=0,c=0,d=0;
    ll n,m;
    cin>>n;
    ll arr[n];
    ll arr2[m];
    for (int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cin>>m;
    for (int i=0;i<m;i++)
        cin>>arr2[i];
    sort(arr,arr+m);
    a = arr[m-1];

    for (int i=0;i<n;i++)
    {
        if (arr[i]>=a)
            break;
        else
        {
            b += (a-arr[i])+1;
        }

    }
    cout<<b<<endl;
}