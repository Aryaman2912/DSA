#include<bits/stdc++.h>
using namespace std;
int precedence(char x){
	if(x=='^')
		return 3;
	else if(x=='*' or x=='/')
		return 2;
	else if(x=='+' or x=='-')
		return 1;
	else 
		return -1;
}
string infix_to_postfix(string s){
	stack<char>op;
	int i=0,n = s.length();
	string res;
	while(i<n){
		// If the character is an operator, append it to the answer string
		if(s[i]!='+' and s[i]!='-' and s[i]!='*' and s[i]!= '/' and s[i]!='(' and s[i]!=')'){
			res += s[i];
		}
		// If the character is an opening parantheses, push it to the stack
		else if(s[i]=='('){
			op.push(s[i]);
		}
		// If the character is a closing parantheses, pop all the elements 
		// upto the opening prantheses and append it to the result string. Then pop the opening parantheses.
		else if(s[i]==')'){
			while(op.top()!='('){
				res += op.top();
				op.pop();
			}
			op.pop();
		}
		// If the character is an operand, pop all the elements in the stack 
		// that have a higher precedence and append it to the result string
		// Then push the operand to the stack
		else{
			while(!op.empty() and precedence(op.top())>precedence(s[i])){
				res += op.top();
				op.pop();
			}
			op.push(s[i]);
		}
		i++;
	}
	// Empty the stack
	while(!op.empty()){
		res += op.top();
		op.pop();
	}
	return res;

}
int main(){
	string s;
	cout << "Enter the infix expression: \n";
	cin >> s;
	// No error handling has been done on the assumption that
	// the infix exp is correct.
	string res = infix_to_postfix(s);
	cout << "The postfix expression is: \n" << res <<"\n";
}