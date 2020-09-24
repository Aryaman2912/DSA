// The below program contains the implementation of
// the bubble sort algorithm

#include<bits/stdc++.h>
using namespace std;

// Function to implement bubble sort
void bubble_sort(int n,vector<int> &a){
	// The bool variable checks if a swap has taken place
	bool swapped = false;
	for(int i = 0; i < n; i++){
		swapped = false;
		for(int j = 0; j < n-1-i; j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				swapped = true;
			}
		}
		// If there are no swaps in any particular iteration,
		// then the array is sorted
		if(!swapped){
			return;
		}
	}
}

// Main function
int main(){
	int n;
	cout << "How many numbers are you entering?\n";
	cin >> n;
	vector<int>arr(n);
	cout << "Enter the array elements:\n";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	bubble_sort(n,arr);
	cout << "The sorted array is\n";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}