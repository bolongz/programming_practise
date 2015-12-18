#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_T = 1005;
const int MAX_W = 35;
int T, W;
int dp[MAX_T][MAX_W];
int apple[MAX_T];
int main(){
	freopen("in.txt", "r",stdin);
	scanf("%d %d", &T, &W);
	for(int i = 1 ; i <= T; i++)
		scanf("%d", &apple[i]);
	if(apple[1] == 1){
		dp[1][0] = 1;
		dp[1][1] = 0;
	}
	if(apple[1] == 2){
		dp[1][0] = 0;
		dp[1][1] = 1;
	}
	for(int i = 2 ; i <= T; i++){
		for(int  j = 0; j <= W; j++){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
				if( (apple[i] - 1) == (j % 2)){
					dp[i][j]++;
				}
			}
		}

	int maxn = -1;
	for(int i = 0; i <= W; i++)
		if(maxn < dp[T][i]) maxn = dp[T][i];
	printf("%d\n",maxn);
	return 0;
}
