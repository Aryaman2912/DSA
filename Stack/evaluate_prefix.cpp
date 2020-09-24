#include<bits/stdc++.h>
using namespace std;

// Function to evaluate a binary expression
int perform(char x, int a, int b){
	if(x=='+'){
		return a+b;
	}
	if(x=='-'){
		return a-b;
	}
	if(x=='*'){
		return a*b;
	}
	if(x=='/'){
		return a/b;
	}
	if(x=='^'){
		return pow(a,b);
	}
	return 0;
}

// Function to evaluate the expression of the string
int evaluate(string s){
	stack <int> op;
	int n = s.length(),i = n-1;
	while(i>=0){
		//If the character is an operand, push it into the stack
		if(s[i]>='0' and s[i] <='9')
			op.push(int(s[i])-48);
		// Else, remove the top two integers of the stack and evaluate the binary expression
		else{
			int op1 = op.top();
			op.pop();
			int op2 = op.top();
			op.pop();
			int op3 = perform(s[i],op1,op2);
			op.push(op3);
		}
		i--;
	}
	return op.top();
}

int main(){
	string exp;
	// For the sake of simplicity, only single digits expressions are being evaluated
	cout << "Enter the prefix expression(Single digits please): \n";
	cin >> exp;
	int ans = evaluate(exp);
	cout <<"The value of the expression is " << ans << ".\n";
}