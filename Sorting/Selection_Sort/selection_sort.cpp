#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define rloop(i,a,b) for(ll i = ll(a); i >= ll(b); --i)
#define sloop(i,a) for (std::set<ll>::iterator i = a.begin(); i != a.end(); ++i)
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;

void selection_sort(vector <ll> &a,ll n){
    for(ll i = 0;i < n-1; i++){
        ll min = i;  
        cout << min << "\n";   
        for(ll j = i+1;j < n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        ll temp = a[min];
        a[min] = a[i];
        a[i] = temp;                                                                                                                                            
    }
}

int main()
{
    ll n;
    cout  << "Enter the number of elements: ";   
    cin >> n;
    vector <ll> a(n),sorted_a(n);
    cout << "Enter the elements: \n";
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    selection_sort(a,n);
    cout << "The sorted array is:\n";
    loop(i,0,n){
        cout << a[i] << " ";
    }
    cout << "\n";
}