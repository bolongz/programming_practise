#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int max_n = 5000;

vector<int> dir(max_n);
vector<int> f(max_n);

int N = 0;

int solve(const int &k){ //Here we take all the possible k
	int res = 0;
	int sum = 0;
	for(int i = 0 ; i < N; i++){
		f[i] = 0;
	}
	for(int  i = 0; i + k <= N; i++){
		if((dir[i] + sum) %2 != 0){
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if(i - k + 1 >= 0){
			sum -= f[i-k+1];
		}
	}
	for(int i = N -k + 1; i < N; i++){
		if((dir[i] + sum) % 2 != 0){
			return -1;
		}
		if( i - k + 1 >= 0){
			sum  -= f[i - k + 1];
		
		}
	}
	return res;
}

int main(){
	cin >> N;
	char c;
	for(int i = 0 ; i < N ;i++){
		cin >> c;
		if(c == 'F') dir[i] = 0;
		else dir[i] = 1;
	}
/*	for(int i = 0; i < N ; i++){
		cout << dir[i];
	}
	cout << endl;
*/	int K = 1, M = N;
	for(int  k = 1; k <= N; k++){
		int m = solve(k);
		if(m >= 0 && M > m){
			K = k;
			M = m;
		}
	}
	printf("%d %d\n", K, M);
	return 0;
}

	
