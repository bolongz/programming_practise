#include<iostream>
#include<vector>
using namespace std;
const int MAX_V = 100;
const int INF = 100000000;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s){
	for(int i = 0 ; i < MAX_V; i++){
		d[i] = INF;
		used[i] = false;
	}
	while(true){
		int v = -1;
		for(int i = 0 ; i< V; i++){
			if( !used[i] &&(v == -1 ||  d[i] < d[v])) v = i;
		}
		if(v == -1) break;
		used[v] = true;
		for(int i = 0 ; i < V; i++){
			d[i] = min(d[i], d[v] + d[i][v];
		}
	}
}


