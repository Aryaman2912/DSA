//Implementation of the merge sort algorithm.

#include<bits/stdc++.h>
using namespace std;
#define M 1e9 + 7
#define C 998244353
#define pi 3.14159265359
#define loop(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define rloop(i,a,b) for(ll i = ll(a); i >= ll(b); --i)
#define sloop(i,a) for (std::set<ll>::iterator i = a.begin(); i != a.end(); ++i)
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;

//Function to merge the sorted components
void merge(std::vector<ll> &arr,ll l,ll m,ll r){

    ll i=0,j=0,k=0,n1 = m-l+1,n2 = r-m;
    std::vector<ll> L(n1),R(n2);       // Temp vectors
    loop(i,0,n1){
        L[i] = arr[l+i];
    }
    loop(i,0,n2){
        R[i] = arr[m+1+i];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k] = (L[i]);
            i++;
            k++;
        }
        else{
            arr[k] = (R[j]);
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = (L[i]);
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = (R[j]);
        j++;
        k++;
    }
    
    
}

//Function to sort individual components
void merge_sort(std::vector<ll> &arr,ll l,ll r){
    
    if(l<r){
        ll m = l + (r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
      
}

int main()
{
    ll n;
    cout << "How many numbers do you want to sort? ";
    cin >> n;
    vector<ll> arr(n);
    cout << "Enter the numbers:\n";
    loop(i,0,n){
        cin >> arr[i];
    }
    merge_sort(arr,0,n-1);      // Function call
    cout << "The sorted array is: \n";
    loop(i,0,n){
        cout << arr[i] << " ";
    }
    cout<<"\n";
}