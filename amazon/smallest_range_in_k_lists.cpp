#include <queue>
#define ll long long
void findSmallestRange(int arr[][N], int n, int k)
{
    int pt[k];
    int ma = INT_MIN;
    fill(pt,pt+k,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    for (int i=0;i<k;i++){
        pq.push(make_pair(arr[i][0],i));
        ma = max(arr[i][0],ma);
    }
    int res = INT_MAX;
    int x,y,z,low,high,temp;
    while(1){
        x = pq.top().first;
        temp = (ma-x+1);
        if (temp<res){
            res = temp;
            low = x;
            high = ma;
        }
        y = pq.top().second;
        pq.pop();
        pt[y]++;
        if (pt[y]==n)
            break;
        pq.push(make_pair(arr[y][pt[y]],y));
        if (arr[y][pt[y]]>ma)
            ma = arr[y][pt[y]];
    }
    cout<<low<<" "<<high<<endl;
}