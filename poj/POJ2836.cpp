/*
 * This is the solution for POJ2836
 * The method used here is DP
 */

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int max_n = 16;
const int inf = 1000000000;
int N;
int x[max_n], y[max_n];

int circle[max_n * max_n]; // deposite the number of the point in the square i 
int area[max_n * max_n]; // depisite the area of the square i;
int dp[1 << max_n];


int main(){

	freopen("in.txt", "r", stdin);

	while(scanf("%d", &N) == 1 && N){
		for(int i =  0 ; i < N; i++){
			scanf("%d %d", &x[i], &y[i]);
		}
		int cnt = 0;
		for(int i = 0 ;i < N ;i++){
			for(int j = 0; j < i; j++){
				circle[cnt] = 0;
				for(int k = 0 ; k < N ; k++){
					if((x[i] - x[k]) *( x[k] - x[j]) >= 0 &&
						(y[i] - y[k]) *( y[k] - y[j]) >= 0)
						circle[cnt] |= (1 << k);
				}
				if( x[i] == x[j]) area[cnt] = abs(y[i] - y[j]);
				else if( y[i] == y[j]) area[cnt] = abs(x[i] - x[j]);
				else area[cnt] = abs((x[i] - x[j]) * (y[i] - y[j]));
				cnt++;
			}
		}
		for(int i = 0 ; i < (1 << N) ;i++){
			dp[i] = inf;
		}
		dp[0] = 0;
		for(int s = 0 ; s < ( 1<<N); s++){
			for(int i = 0 ; i < cnt; i++){
				int t = s | circle[i];
				if(t == s) continue;
				dp[t] = min(dp[t], dp[s] + area[i]);
			}
		}
		cout << dp[(1 << N) - 1] << endl;
	}
	return 0;
}

