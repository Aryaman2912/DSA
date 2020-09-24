#include<bits/stdc++.h>

using namespace std;

// Function to check if the string has balanced parentheses
bool Check(string s){
	stack <char> par;
	int n = s.length(),i=0;
	// If the input character is an opening parentheses,push it to the stack
	// else pop the top if the top is a corresponding opening parenthesis
	while(i<n){
		if(s[i]=='[' or s[i]=='{' or s[i]=='('){
			par.push(s[i]);
		}
		else if(s[i]==']'){
			if(par.top()=='[')
				par.pop();
		}
		else if(s[i]=='}'){
			if(par.top()=='{')
				par.pop();
		}
		else if(s[i]==')'){
			if(par.top()=='(')
				par.pop();
		}
		i++;
	}
	// If the stack is empty, string is balanced, otherwise it's not
	return par.empty();
}
int main(){
	string s;
	cout << "Enter the string\n";
	cin >> s;
	if(Check(s))
		cout << "The string is balanced\n";
	else
		cout << "The string is not balanced\n";
}