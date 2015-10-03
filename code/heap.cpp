#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_N = 100;
int sz = 0;
int heap[MAX_N];

void heapPush(int x){
// inseart a number in a heap;
	int i = sz++;
	while ( i > 0){
		int p = (i-1)/2;
		if(heap[p] <= x) break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}
int heapPop(){
	int ret = heap[0]; // the minize number of the heap
	cout << ret << "ret" << endl;
	int last = heap[--sz]; // the last element of heap
	int i = 0;
	while(i * 2 + 1 < sz){
		int l = i * 2 + 1, r = i * 2 + 2;
		if( r < sz && heap[r] < heap[l]) l = r; // take the min number between two leaves
		if( heap[l] >= last) break; 
		heap[i] = heap[l];
		i = l;
	}
	heap[i] = last;
	cout << ret << "ret ret" << endl;
	return ret;
}

int main(){
	
	heapPush(100);
	heapPush(5);
	heapPush(9);
	heapPush(32);
	heapPush(65);
	heapPush(72);
//	cout << heapPop() << " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << heapPop() << endl; ; //<< " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << heapPop() << endl; ; //<< " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << heapPop() << endl; ; //<< " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << heapPop() << endl; ; //<< " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << heapPop() << endl; ; //<< " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << heapPop() << endl; ; //<< " " << heapPop() << " " << heapPop() << " " <<  heapPop() << " " << heapPop() << " " << heapPop() << endl;
	cout << " ---------------------" << endl;
	priority_queue<int, vector<int>, greater<int> > que;
	que.push(100);
	que.push(5);
	que.push(9);
	que.push(32);
	que.push(65);
	que.push(72);
	cout << que.top() << " ";
	 que.pop();
	cout << que.top() << " ";
	 que.pop();
	cout << que.top() << " ";
	 que.pop();
	cout << que.top() << " ";
	 que.pop();

	cout << que.top() << " ";
	 que.pop();
	cout << que.top() << " ";
	 que.pop();
	return 0;
}
