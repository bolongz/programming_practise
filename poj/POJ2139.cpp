/* POJ2139 Six Degrees of Cowwin Bacon */
/* The method used here is Floyd-Warshall */

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;

const int MAX_N = 301;
const int INF = 1 << 20;
int d[MAX_N][MAX_N];
int m[MAX_N];
int N, M;

void warshall_floyd(){
	for(int k = 0 ; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main(){

	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for( int i = 0; i < MAX_N; i++){
		fill(d[i], d[i] + MAX_N, INF);
		d[i][i] = 0;
	}
	for(int i = 0 ; i < M; i++){
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%d", &m[j]);
		}
		for(int k = 0; k < n ;k ++){
			for(int j = k + 1; j < n ;j ++){
				d[m[k] - 1][m[j] - 1] = d[m[j] - 1][m[k] - 1] = 1;
			}
		}
	}
	warshall_floyd();
	int sum = 0, min = INF;
	for(int i = 0 ; i < N; i++){
		sum = 0;
		for(int j = 0; j < N; j++){
			sum += d[i][j];
		}
		if( min > sum) min = sum;
	}
	int  ans = int(100 * double(min) / (N - 1));
	printf("%d\n", ans);
	fclose(stdin);
	return 0;
}
	



	
