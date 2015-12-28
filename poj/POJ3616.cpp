#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX_N = 1000000;
const int MAX_M = 1000;
int N, M, R;
int dp[MAX_M +1];
struct itv{
	int start;
	int end;
	int eff;
};

itv p[MAX_M+1];

bool comp(const itv &a, const itv &b){
	return a.start < b.start;
}
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &R);
	for(int i = 0 ; i < M ; i++)
		scanf("%d %d %d", &p[i].start, &p[i].end, &p[i].eff);
	sort(p, p + M, comp);
	for(int i = 0 ; i < M ; i++)
		dp[i] = p[i].eff;
	for(int j = 0; j < M; j++){
		for(int i = j +1; i <= M; i++){
				if( p[i].start >= p[j].end + R){
					dp[i] = max(dp[i], dp[j] + p[i].eff);
				}
		}
	}
	int ans = 0 ;
	for(int i = 0; i < M; i++){
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
	
	



