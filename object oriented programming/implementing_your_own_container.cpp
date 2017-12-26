#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define num 10000
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
	if (n <= 1)  {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}
	
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

inline int binSearch(int arr[],int val,int b){
    int low=0,high=b-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>val){
            high=mid-1;
        }
        else if(arr[mid]<val){
            low=mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

template<class T>
class vec{
	int size;
	int capacity;	
	T *arr;
public:
	vec<T>(int cap);
	vec<T>();
	void insert(T x);
	int len();
	void print();
	void del(int k);
	// method to be called when we wish 
	T operator [](int x);
};

// constructor to be called when the limit of the container is given to us.
template<class T>
vec<T> :: vec(int cap){
	capacity = cap;
	size = 0;
	arr = new T[capacity];
}

// constructor to be called when the limit of the vector is not given to us.
template<class T>
vec<T> :: vec(){
	capacity = num;
	size = 0;
	arr = new T[num];
}


// method to be called when we need to insert something in the vector.
template<class T>
void vec<T> :: insert(T x){
	if (size == capacity){
		cout<<"overflow error"<<endl;
		return;
	}
	size++;
	ll i = size-1;
	arr[i] = x;
}

// method to be called when we need to print our contianer
template<class T>
void vec<T> :: print(){
	for (int i=0;i<size;i++)
		cout<<arr[i]<<" ";
}

// method to be called when we need to get the size of a contianer
template<class T>
int vec<T> :: len(){
	return size;
}


// method to be called when we need to del a element at a particular index  from a container
template<class T>
void vec<T> :: del(int k){

	if (k>=size){
		cout<<"overflow error"<<endl;
		return;
	}

	for (int i=k;i<size-1;i++){
		arr[i] = arr[i+1];
	}
	size--;
}

template<class T>
T vec<T> :: operator [](int x){
	return arr[x];
}


int main(){
	vec<int>v;
	vec<string>v2(4);
	v.insert(3);
	v.insert(4);
	v2.insert("raghav");
	v2.insert("raman");
	v2.insert("deepak");
	v2.insert("shreya");
	v2.insert("dibakar");
	v2.print();
	cout<<endl;
	v.print();
	ll x = v2.len();
	ll y =  v.len();
	v.del(1);
	v2.del(0);
	v.print();
	v2.print();

	string bb= v2[0];
	cout<<bb<<endl;
}

