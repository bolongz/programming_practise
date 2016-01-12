/* this the solution for POJ3259
 * The method used here is Bellman=ford
 * need to check negative edge
 */

#include<iostream>
#include<stdio.h>

using namespace std;

int dis[1010];
const int INF = 1 << 26;
struct edge{
	int from, to, cost;
};

edge es[6000];
int N, M, W;
int F;
int index;
int bellman(){
	for(int i = 1 ; i <= N; i++) dis[i] = INF;
	dis[1] = 0;
	for(int i = 0 ; i < N-1; i++){
		for(int j = 0 ;j < index; j++){
			edge e = es[j];
			if(dis[e.from] < INF && dis[e.to] > dis[e.from] + e.cost){
				dis[e.to] = dis[e.from] + e.cost;
			}
		}
	}
	 for(int k = 0; k < index; k++)  
		if(dis[es[k].from] < INF && dis[es[k].to] > dis[es[k].from] + es[k].cost)  
			return true; 
	 return false;
}
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d", &F);
	while(F--){
		index = 0;
		scanf("%d %d %d", &N, &M, &W);
		for(int i = 1; i <= M; i++){
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			es[index].from = from;
			es[index].to = to;
			es[index +1].from = to;
			es[index +1].to = from;
			es[index++].cost = cost;
			es[index++].cost = cost;
		}
		for(int i = 1 ; i <= W; i++){
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			es[index].from = from;
			es[index].to = to;
			es[index++].cost = -cost;
		}
		if(bellman()){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
			
