// The following program contains an implementation
// of quick sort

#include<bits/stdc++.h>
using namespace std;

// Function to find the index to partition the array
int partition(vector<int> &a,int l,int h){
	int pivot = a[l];
	int i = l,j = h-1;
	while(i<j){
		while(a[i] <= pivot)
			i++;
		while(a[j] > pivot)
			j--;
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	swap(a[l],a[j]);
	return j;
}

// Funtion to implement recursive quicksort
void quicksort(vector<int> &a,int l,int h){
	if(l<h){
		int j = partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}

// Main function
int main(){
	int n;
	cout << "How many elements are you entering\n";
	cin >> n;
	vector<int>arr(n);
	cout << "Enter the elements of the array\n";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	quicksort(arr,0,n);
	cout << "The sorted array is \n";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}