#include<iostream>
#include<vector>
#include<utility>
#include<queue>
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

int dist[MAX_V];
int dist2[MAX_V];
int V;
void second_path(int s){

	dist[0] = 0;
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top(); que.pop();
		int d = p.first, v = p.second;
		if(dist2[v] < d) continue;
		for(int  i = 0 ; i< G[v].size() ;i++){
			edge &e = G[v][i];
			int d2 = d + e.cost;
//		cout<< "d2  " << d2  << " " << dist[e.to] << " " << e.to << endl;
			if(dist[e.to] > d2){
				swap(dist[e.to], d2);
				que.push(P(dist[e.to],e.to));
				//cout << " first "  << e.to << " " << d2 << endl;
			}
			if(dist2[e.to] > d2 && dist[e.to] < d2){
				//swap(dist2[e.to], d2);
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
				cout << e.to << " " << d2 << endl;
			}
		}
	}
}

int main(){
	int V, E;
	cin >> V >> E;
	for(int i = 0 ;i < E; i++){
		edge e;
		int from;
		cin >> from >> e.to >> e.cost;
		G[from].push_back(e);
		edge e2;
		e2.to = from; e2.cost = e.cost;
		G[e.to].push_back(e2);

	}
	fill(dist, dist+V, INF);
	fill(dist2, dist2+V, INF);
	second_path(0);
	cout << dist2[V-1] << endl;;
	return 0;
}
