#include<bits/stdc++.h>

using namespace std;

// Function to reverse the string
string reverse(string s,int n){
	stack<char> strrev;
	int i = 0;
	while(i<n){
		strrev.push(s[i]);
		i++;
	}
	i=0;
	while(!strrev.empty()){
		s[i] = strrev.top();
		i++;
		strrev.pop();
	}
	return s;
}
int main(){
	string s;
	cout << "Enter the string: \n";
	cin >> s;
	int n = s.length();
	s = reverse(s,n);
	cout << "The reversed string is: \n" << s << "\n"; 
}