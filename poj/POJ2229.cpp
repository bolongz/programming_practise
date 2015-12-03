/* This is the programming for POJ2229"
 *
 *The method used here is DP method */

#include<iostream>
#include<stdio.h>

using namespace std;

int N;

long long dp[1000000 + 1];

int solve(){

	dp[1] = 1;
	
	for(int i = 2; i <= N ; i++){

		if( i & 1) {

			dp[i] = dp[i - 1];
		}
		else{

			dp[i] = dp[i - 1] + dp[i / 2];
		}
		dp[i] = dp[i] % 1000000000;
	}
	return dp[N];

}

int main(){
	scanf("%d", &N);
	printf("%d\n", solve());
	return 0;
}
