/* this the solution for POJ3268
 * The method used here is Bellman=ford
 * need to check negative edge
 */

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int INF = 1 << 26;
const int max_n = 1010;
const int max_m = 100010;

vector<int> dis(max_n);
vector<int> dis2(max_n);

struct edge{
	int from, to, cost;
};

vector<edge> es(max_m);
vector<edge> es2(max_m);

int N, M, X;
int bellman(vector<edge> &e1, vector<int> &d, int x){
	for(int i = 1 ; i <= N; i++) d[i] = INF;
	d[x] = 0;
	while(true){
		bool update = false;
		for(int j = 0 ;j < M; j++){
			edge e = e1[j];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update) break;
	}
}
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &X);
	
	for(int i = 0; i < M; i++){
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		es[i].from = from;
		es[i].to = to;
		es[i].cost = cost;
		
		es2[i].from = to;
		es2[i].to = from;
		es2[i].cost = cost;
	}
	bellman(es, dis, X);
	bellman(es2, dis2,X);
	int max = 0;
	for(int i = 1 ; i <= N; i++){
		if(max < (dis[i] + dis2[i])) max = dis[i] +dis2[i];
	}
	cout << max << endl;
	return 0;
}
			
