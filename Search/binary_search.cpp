// This program contains an implementation of recursive binary search.

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define rloop(i,a,b) for(ll i = ll(a); i >= ll(b); --i)
#define sloop(i,a) for (std::set<ll>::iterator i = a.begin(); i != a.end(); ++i)
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;

ll binary_search(vector<ll> &numbers,ll low,ll high,ll num){

    if(low > high)
        return -1;
    ll mid = low + (high-low)/2;
    if(numbers[mid] == num)
        return mid+1;
    if(numbers[mid] < num)
        return binary_search(numbers,mid+1,high,num);
    if(numbers[mid] > num)
        return binary_search(numbers,low,mid-1,num);
    return -1;
}

int main(){

    ll n,pos,num;
    cout << "How many numbers are you entering? \n";
    cin >> n;
    vector<ll>numbers(n);
    cout <<"Enter the numbers in sorted order:\n";
    loop(i,0,n){
        cin >> numbers[i];
    }
    cout << "Which number do you want to search for? \n";
    cin >> num;
    pos = binary_search(numbers,0,n,num);
    if(pos != -1)
        cout << num << " is present is position " << pos << "\n";
    else
        cout << num << " is not present in the array" << "\n";
}