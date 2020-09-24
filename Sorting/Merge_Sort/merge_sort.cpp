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
std::vector<ll> merge(std::vector<ll> &a1,std::vector<ll> &b1){

    std::vector<ll> res;
    std::list<ll>a(a1.begin(), a1.end()),b(b1.begin(), b1.end());

    while(!a.empty() && !b.empty()){
        if(a.front()<b.front()){
            res.pb(a.front());
            a.pop_front();
        }
        else{
            res.pb(b.front());
            b.pop_front();
        }
    }
    while(!a.empty()){
        res.pb(a.front());
        a.pop_front();
    }
    while(!b.empty()){
        res.pb(b.front());
        b.pop_front();
    }
    return res;
}

//Function to sort individual components
std::vector<ll> merge_sort(std::vector<ll> &a,ll n){

    std::vector<ll> A,B;
    if(n==1)
        return a;
    loop(i,0,n/2){
        A.pb(a[i]);
    }
    loop(i,n/2,n){
        B.pb(a[i]);
    }
    A = merge_sort(A,n/2);      // Recursive call 1
    B = merge_sort(B,n-n/2);    // Recursive call 2 
    return merge(A,B);          // Function call to merge the sorted components   
}

int main()
{
    ll n;
    cout << "How many numbers do you want to sort? ";
    cin >> n;
    vector<ll> a(n),b;
    cout << "Enter the numbers:\n";
    loop(i,0,n){
        cin >> a[i];
    }
    a = merge_sort(a,n);      // Function call
    cout << "The sorted array is: \n";
    loop(i,0,n){
        cout << a[i] << " ";
    }
    cout<<"\n";
}