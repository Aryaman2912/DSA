#include<bits/stdc++.h>
using namespace std;

// Function to implement insertion sort
void insertion_sort(vector<int>&numbers,int n){

	for(int i=1;i<n;i++){
		int key = numbers[i],j=i-1;
		// If an element from a[0] to a[i] is greater than the key,
		// it is shifted by one place. This is repeated till 
		// the entire array is traversed.
		while(j>=0 and numbers[j]>key){
			numbers[j+1] = numbers[j];
			j--;
		}
		numbers[j+1] = key;
	}
}

int main(){
	int n;
	cout << "How many numbers are you entering? \n";
	cin >> n;
	vector <int> numbers(n);
	cout <<"Enter the elements of the array: \n";
	for(int i=0;i<n;i++){
		cin >> numbers[i];
	}
	insertion_sort(numbers,n);
	cout << "The sorted array is: \n";
	for(int i=0;i<n;i++){
		cout << numbers[i] << " ";
	}
	cout << "\n";
}