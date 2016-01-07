/*
 * This is the solution for POJ2441
 * DP method is used here
 */

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>

using namespace std;
const int max_n = 12+1;
int fertile[max_n];
int dp[max_n][1 << max_n];
int M, N;
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	memset(fertile, 0, sizeof(fertile));
	for(int i = 1 ; i <= M; i++){
		for(int j = 1 ; j <=N ;j++){
			int c;
			scanf("%d", &c);
			if(c){
				fertile[i] += 1 << (j-1);
			}
		}
	}
	
	for(int i = 0 ;i < (1 << N); i++){

		if((i << 1) &i) continue;
		if(( i & fertile[1]) != i) continue;
		dp[1][i] = 1;
	}
	for(int i = 2; i <= M; i++){
		for(int j = 0 ; j < (1 << N); j++){
			if((j << 1) & j) continue;
			if((fertile[i] &j)!=j) continue;
			for(int k = 0 ; k < (1 << N); k++){
				if((k << 1) & k) continue;
				if((fertile[i-1] &k)!=k) continue;
				if(j & k) continue;
				dp[i][j] = (dp[i][j] +dp[i-1][k]) % 100000000;
			}
		
		}
	}
	int ans = 0;
	for(int i = 0 ; i < (1 << N ); i++){
		ans += dp[M][i];
		ans %=  100000000;
	}
	cout << ans << endl;
	return 0;
}
