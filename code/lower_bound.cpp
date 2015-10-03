#include<iostream>
using namespace std;
int main(){
	const int MAX_N = 1000000;
	int n, k;
	cin >> n >> k;
	int a[MAX_N];
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	int lb = -1, ub = n;
	while(ub - lb > 1){
		int mid = ( ub + lb)/2;
		if( a[mid] >= k){
			ub = mid;
		}else{
			lb = mid;
		}
	}
	cout << ub << endl;
	return 0;
}
