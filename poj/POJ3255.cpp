#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<stdio.h>
using namespace std;



const int MAX_V = 5000;
const int INF = 1000000;
struct edge{
	int to;
	int cost;
};
vector<edge> G[MAX_V];

typedef pair<int, int> P; //the first is the cost, the second is the point number;
priority_queue<P, vector<P>, greater<P> > que;

int dist[MAX_V]; // shortest path
int dist2[MAX_V]; // the second shortest path
int V;
void second_path(int s){

	dist[0] = 0;
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top(); que.pop();
		int d = p.first, v = p.second;
		if(dist2[v] < d) continue; //discard this points
		for(int  i = 0 ; i< G[v].size() ;i++){
			edge &e = G[v][i];
			int d2 = d + e.cost;
			if(dist[e.to] > d2){
				swap(dist[e.to], d2);
				que.push(P(dist[e.to],e.to));
			}
			if(dist2[e.to] > d2 && dist[e.to] < d2){ //update the second shortest path 
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
}

int main(){
	freopen("in.txt","r", stdin);
	int V, E;
	scanf("%d %d", &V , &E);
	for(int i = 0 ;i < E; i++){
		edge e;	
		int a, b,c;
		scanf("%d %d %d", &a , &b, &c);
		e.to = b - 1; e.cost = c;
		G[a-1].push_back(e);
		edge e2;
		e2.to = a - 1; e2.cost = e.cost;
		G[e.to].push_back(e2);

	}
	fill(dist, dist+V, INF);
	fill(dist2, dist2+V, INF);
	second_path(0);
	cout << dist2[V-1] << endl;;
	fclose(stdin);
	return 0;
}
