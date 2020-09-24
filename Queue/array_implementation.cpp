#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int queue_[MAXN];
int front = -1,rear = -1;

bool IsEmpty(){
	if(front==-1 and rear == -1){
		return true;
	}
	return false;
}

void Push(int x){
	queue_[++front] = x;
}

void Pop(){
	front++;
}

int Front(){
	return queue_[rear];
}
void Print(){
	int i = rear;
	if(rear==-1)
		rear++;
	cout << "The current queue is \n";
	while(i != front){
		cout << queue_[i] << " ";
		i++;
	}
	// cout << rear << " " << front;
	cout << endl;
}
int main(){
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Print();
	while(1){
		cout << "Press 1 to enter an element\nPress 2 to delete an element\nPress 3 to obtain the value of the first element\nPress 4 to print the queue\nPress 0 to stop\n";
		int a;
		cin >> a;
		if(!a)
			break;
		else if(a==1){
			int x;
			cout << "Enter the number you want to push to the queue: ";
			cin >> x;
			Push(x);
			Print();
		}
		else if(a==2){
			Pop();
			Print();
		}
		else if(a==3){
			cout << "The element at the front of the queue is " << Front() << "\n";
		}
		else if(a==4){
			Print();
		}
		else{
			cout << "Invalid\n";
		}
	}

}