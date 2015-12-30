/*This is the solution for POJ2686
 * the method used here is DP
 */

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;

const int max_n = 8;
const int max_m = 30;
const double INF = 1000000000000.0;
int n, m,p, a, b;

int t[max_n];
int d[max_m][max_m];
double dp[1 << max_n][max_m];
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d %d %d %d %d", &n, &m, &p, &a, &b)){
		if(n == 0 && m == 0 && p == 0 && a == 0 && b == 0) break;
		for(int i = 0 ; i < max_m ; i++){
			for(int j = 0 ;j  < max_m ;j ++){
				d[i][j] = -1;
			}
		}
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &t[i]);
		}
		int  _i, _j;
		for(int i = 0 ; i < p; i++){
			scanf("%d %d", &_i, &_j);
			scanf("%d", &d[_i-1][_j-1]);
			d[_j-1][_i-1] = d[_i-1][_j-1];
		}
		for( int i = 0 ; i < 1 << n ; i++){
			for(int j = 0 ; j < m; j++){
				dp[i][j] = INF;
			}
		}
		dp[(1 << n) - 1][a - 1] = 0.0;
		double res = INF;
		for(int S = ( 1 << n ) -1; S >= 0; S--){
			res = min(res, dp[S][b-1]);
			for( int v = 0 ; v  < m ; v++){
				for(int i = 0 ; i < n ; i++){
					if ( S >> i & 1){
						for ( int u = 0; u < m; u++){
							if(d[v][u] >= 0){
								dp[S & ~(1 << i)][u] = min(dp[S&~(1 << i)][u], dp[S][v] + double(d[v][u])/t[i]);
							}
						}
					}
				}
			}
		}
		if(abs(res - INF) < 0.00001){
			printf("Impossible\n");
		}else{
			printf("%.3f\n", res); // %lf will be wrong
		}
	}
	fclose(stdin);
	return 0;
}
