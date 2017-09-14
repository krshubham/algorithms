

    #include <bits/stdc++.h>
    using namespace std;
    void build(int *arr,int *segtree,int low,int high,int pos){
        if (low == high){
            segtree[pos] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(arr,segtree,low,mid,2*pos+1);
        build(arr,segtree,mid+1,high,2*pos+2);
        segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);
    }
     
    void solution(int *segtree,int *lazy,int low,int high,int pos,int m){
        int diff;
        //cout<<"lazy[pos]= "<<lazy[pos]<<endl;
        if (lazy[pos] != 0){
            diff = lazy[pos];
            lazy[pos] = 0;
            if (segtree[pos]-diff<1)
                segtree[pos] = 1;
            else
                segtree[pos] -= diff;
            if (low != high){
                lazy[2*pos+1] += diff;
                lazy[2*pos+2] += diff;
            }
                
        }
     
        if (segtree[pos]>m){
            if (segtree[pos] == 1)
                segtree[pos] = 1; 
            else
                segtree[pos]--;
            if (low != high){
                lazy[2*pos+1]++;
                lazy[2*pos+2]++;    
            }
            
            return;
        }
        if (low == high)
            return;
        int mid = (low+high)/2;
        solution(segtree,lazy,low,mid,2*pos+1,m);
        solution(segtree,lazy,mid+1,high,2*pos+2,m);
     
    }
     
    void update(int *segtree,int *lazy,int low,int high,int pos){
        int diff;
        //<<"lazy[pos]= "<<lazy[pos]<<endl;
        if (lazy[pos] != 0){
            diff = lazy[pos];
            if (segtree[pos] - diff < 1)
                segtree[pos] = 1;
            else
                segtree[pos] -= diff;
            if (low !=high){
                lazy[2*pos+1] += diff;
                lazy[2*pos+2] += diff;    
            }
            
     
        }
        /*cout<<"low = "<<low<<endl;
        cout<<"high= "<<high<<endl;*/
        if (low == high)
            return;
        int mid = (low+high)/2;
        update(segtree,lazy,low,mid,2*pos+1);
        update(segtree,lazy,mid+1,high,2*pos+2);
     
    }
     
     
    void print(int *segtree,int low,int high,int pos){
        //cout<<"pos= "<<pos<<endl;
        if (low == high){
            cout<<segtree[pos]<<" ";
            return;
        }
        int mid = (low+high)/2;
        print(segtree,low,mid,2*pos+1);
        print(segtree,mid+1,high,2*pos+2);
    }
     
     
     
    int main(){
        int n,t,m;
        cin>>n;
        int arr[n];
        int segtree[4*n];
        int lazy[4*n];
        fill(segtree,segtree+(4*n),0);
        fill(lazy,lazy+(4*n),0);
        for (int i=0;i<n;i++)
            cin>>arr[i];
        build(arr,segtree,0,n-1,0);
        
        /*for (int i=0;i<(4*n);i++){
                if (segtree[i] != 0){
                    cout<<segtree[i]<<" ";
            }
     
        }*/
        cin>>t;
        while(t--){
            cin>>m;
            solution(segtree,lazy,0,n-1,0,m);
            
            
        }
        
          /*for (int i=0;i<4*n;i++){
            if (segtree[i] != 0)
                cout<<segtree[i]<<" ";
            cout<<lazy[i]<<" ";
            cout<<endl;
        }
        cout<<endl;*/
        update(segtree,lazy,0,n-1,0);

     
     
        print(segtree,0,n-1,0);
     
     
    }

