/*
 * This is the solution for POJ2441
 * DP method is used here
 */

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>

using namespace std;
const int max_n = 20+1;
bool like[max_n][max_n];
int dp[2][1 << 20];
int N, M;
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	memset(like, 0, sizeof(like));
	for(int i = 1 ; i <= N; i++){
		int n;
		scanf("%d", &n);
		for(int j = 0 ; j <n ;j++){
			int c;
			scanf("%d", &c);
			like[i][c] = true;
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 0 ; j < (1 << M); j++){
			if(dp[(i-1)& 1][j]){
				for(int k = 1; k <= M; k++){
					if(like[i][k] & (j!= (j|1<<(k-1)))){
						dp[i&1][j|(1<<(k-1))] += dp[(i-1)&1][j];
					}
				}
			}
		}
		memset(dp[(i-1) & 1], 0, sizeof(dp[(i-1) & 1]));
	}
	int ans = 0;

	for(int i = 0 ; i < (1 << M); i++){

		ans += dp[N &1][i];
	}
	cout << ans << endl;
	return 0;
}
