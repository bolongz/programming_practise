#include<iostream>
#include<vector>
using namespace std;
struct edge{
	int from;
	int to;
	int cost;
};
const int INF = 1000000000;
const int MAX_V = 100;
const int MAX_E = 100;
edge es[MAX_E];
int d[MAX_V];
int V, E;
void shortest_path(int s){
		d[s] = 0;
		while(true){ // keep updating until all the point has been scaned
			bool update = false;
			for(int i = 0 ; i < E; i++){
				edge e = es[i];
				if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
					update = true;
				}
			}
			if(!update) break;
		}
}

void find_negative_loop(){
	for(int i = 0; i < MAX_V ; i++) d[i] = 0;
	for(int i = 0 ; i < V; i++)
		for(int j = 0; j < E; j++){
			edge e = es[i];
			if(d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				if( i == V -1) cout << "Yes" << endl;
			}
		}
	cout << "No!" << endl;
}
int main(){
	for(int i = 0 ; i<MAX_V; i++) d[i] = INF;
	int s;
	cin >> V >> E;
	cin >> s;
	for(int i = 0 ; i< E; i++)
		cin >> es[i].from >> es[i].to >> es[i].cost;
	shortest_path(s);
	return 0;



}


