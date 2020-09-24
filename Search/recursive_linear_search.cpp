// This program is an implementation of a recursive linear search algorithm.
// Searching for names is case sensitive.

#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define rloop(i,a,b) for(ll i = ll(a); i >= ll(b); --i)
#define sloop(i,a) for (std::set<ll>::iterator i = a.begin(); i != a.end(); ++i)
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;

ll search_num(vector<ll> &numbers,ll low,ll high,ll num){
    if(low>=high)
        return -1;
    if(numbers[low]==num)
        return low+1;
    return search_num(numbers,low+1,high,num);
}

ll search_name(vector<string> &names,ll low,ll high,string name){
    if(low>=high)
        return -1;
    if(names[low]==name)
        return low+1;
    return search_name(names,low+1,high,name);
}

int main()
{
    string s;
    cout << "Do you want to search for a number or a name? " << "\n";
    cin >> s;
    if(s == "number"){
        ll n,num,pos;
        cout << "How many numbers are you entering? " << "\n";
        cin >> n;
        vector<ll> numbers(n);
        cout << "Enter the numbers: " << "\n";
        loop(i,0,n)
            cin >> numbers[i];
        cout << "Which number are you searching for? " << "\n";
        cin >> num;
        pos = search_num(numbers,0,n,num);
        if(pos != -1)
            cout << num << " is present at position " << pos<<"\n";
        else
            cout << num << " is not present in the array" << "\n";
    }
    else if(s == "name"){
        ll n,pos;
        string name;
        cout << "How many names are you entering? " << "\n";
        cin >> n;
        vector<string> names(n);
        cout << "Enter the names: " << "\n";
        loop(i,0,n)
            cin >> names[i];
        cout << "Which name are you searching for? " << "\n";
        cin >> name;
        pos = search_name(names,0,n,name);
        if(pos != -1)
            cout << name << " is present at position " << pos<<"\n";
        else
            cout << name << " is not present in the array" << "\n";
    }
}