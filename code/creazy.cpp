#include<iostream>
#include<vector>
using namespace std;
int main(){
	
	const int MAX_N = 50;
	int N;
	cin >> N;
	int m[MAX_N][MAX_N];
	int a[MAX_N];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0; j < N; j++){
			cin >> m[i][j];
		}
	}
	for(int i = 0 ; i < N ; i++){
		a[i] = -1;
		for(int j = 0 ; j < N ; j++){
			if(m[i][j] == 1) a[i] = j;
		}
	}
	int res = 0;
	for(int i = 0 ; i < N ; i++){
		int pos = -1;
		for(int j = i ; j < N ; j ++){
			if( a[j] <= i){
				pos = j;
				break;
			}
		}
		for(int j = pos; j > i ; j--){
			swap(a[j], a[j-1]);
			res ++ ;
		}
	}
	cout << res << endl;
	return 0;
}

