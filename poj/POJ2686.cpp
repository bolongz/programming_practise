#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int max_n = 8;
const int max_m = 10;
const double INF = 1 << 20;
int n, m,p, a, b;

vector<int> t(max_n);
vector<vector<int>  > d(max_m);
vector<vector<double> > dp( 1 << max_m);

int main(){
	for(int i = 0 ; i < max_m; i++){
		d[i].resize(max_m);
	}
	for(int i = 0 ; i < 1 << max_m; i++){
		dp[i].resize(max_m);
	}
	for(int i = 0 ; i < max_m ; i++){
		for(int j = 0 ;j  < max_m ;j ++){
			d[i][j] = -1;
		}
	}
	freopen("in.txt","r",stdin);
	while(scanf("%d %d %d %d %d", &n, &m, &p, &a, &b)){
		if(n == 0 && m == 0 && p == 0 && a == 0 && b == 0) break;
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &t[i]);
		}
		int  _i, _j;
		for(int i = 0 ; i < p; i++){
			scanf("%d %d", &_i, &_j);
			scanf("%d", &d[_i][_j]);
		}
		for( int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m; j++){
				dp[i][j] = INF;
			}
		}
		dp[(1 << n) - 1][a - 1] = 0;
		double res = INF;
		for(int S = ( 1 << n ) -1; S >= 0; S--){
			res = min(res, dp[S][b-1]);
			for( int v = 0 ; v  < m ; v++){
				for(int i = 0 ; i < n ; i++){
					if ( S>> i &1){
						for ( int u = 0; u < m; u++){
							if(d[v][u] >= 0){
								dp[S & ~(1 << i)][u] = min(dp[S&~(1 << i)][u], dp[S][u] + (double)d[v][u]/t[i]);
							}
						}
					}
				}
			}
		}
		if(res == INF){
			printf("Impossible\n");
		}else{
			printf("%lf\n", res);
		}
	}
	fclose(stdin);
	return 0;
}
