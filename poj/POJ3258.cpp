#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAX_N = 50005;
const int INF = 1000000000;
int L = 0;
int N = 0;
int M = 0;
int _min, _smin;
int x[MAX_N];
int d[MAX_N];
bool C(int d){
	int last = 0;
	for(int i = 1 ; i< M  ; i++){
		int crt = last + 1;
		while(crt < N && (x[crt] - x[last]) < d){
			crt++;
		}
		if(crt == N){
			return false;
		}
		last  = crt;
	}
	return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &L, &N, &M);
	M = N  + 2 - M;
	for (int i = 0 ; i < N ; i++){
		scanf("%d", &x[i]);
	}
	x[N] = 0;
	x[N+1] = L;
	sort(x, x+N +2);
	N = N+2;
	int _min = INF, _smin = INF, t;
	for(int i = 1 ;i < N ; i++){
		if(x[i]- x[i- 1]  < _min){
			_min = x[i] - x[i-1];
		}
	}
	for(int i = 1; i <N ;i++){
		t = x[i] - x[i-1];
		if( _smin > t  &&  t > _min){
			_smin = t;
		}
	}
	int lb = 0 , ub = INF;
	while(ub - lb > 1){
		int mid = (lb + ub) /2;
		if(C(mid)){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	printf("%d\n", lb);
	fclose(stdin);
	return 0;
}
