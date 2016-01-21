/* this the solution for POJ3273
 * the method used here is Binary search
 */


#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
const int max_n = 100020;

int N, M;
int d[max_n];
bool C(int v){
	int sum = 0;
	int s = 1;
	for(int i = 0 ; i < N; i++){
		sum += d[i];
		if(sum > v){
			sum = d[i];
			++s;
		}
	}
	if(s > M ) return true;
	return false;
}

int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int  l = 0 , h = 0;;
	for(int i = 0 ; i < N; i++){
		scanf("%d", &d[i]);
		if(d[i] > l) l = d[i];
		h += d[i];
	}
	while(l < h){	
		int mid = (l +h)/2;
		if(C(mid)) l = mid +1;
		else h = mid;
	}
	cout << l << endl;
	return 0;
}
