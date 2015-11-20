/* This is the program for POJ3176 */
/* The method used here is dynamic programming */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_N = 350;
int bowl[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int N;
int main(){
	freopen("in.txt", "r", stdin);
	memset(cost, 0, sizeof(cost));
	scanf("%d", &N);
	for(int i = 0 ;i < N; i++){
		for(int j = 0; j < i + 1; j++){
			scanf("%d", &bowl[i][j]);
		}
	}
	int index = 0;
	for(int i = 0; i < N ; i++){
		if( i == 0){
			index = 0;
			cost[0][0] = bowl[0][0];
		}else{
			for(int j = 0 ; j < i + 1 ;j ++){

				if( j == 0){
					cost[i][j] = max(cost[i][j], bowl[i][j] + cost[i-1][j]);
				}else if( j == i){
					cost[i][j] = max(cost[i][j], bowl[i][j] + cost[i-1][j - 1]);
				}else{
					if( j + 1 == i){
						cost[i][j] = max(cost[i][j], bowl[i][j] + cost[i-1][j]);
						cost[i][j] = max(cost[i][j], bowl[i][j] + cost[i-1][j- 1]);
					}else{
						cost[i][j] = max(cost[i][j], bowl[i][j] + cost[i-1][j]);
						cost[i][j] = max(cost[i][j], bowl[i][j] + cost[i-1][j- 1]);
					}
				}
			}
		}
	}
	int max = 0;
	for(int i = 0 ;i < N; i++){
		if(max < cost[N-1][i] ) max = cost[N-1][i];
	}
	printf("%d\n", max);
	fclose(stdin);
	return 0;
}
