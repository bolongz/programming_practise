#include<iostream>
#include<vector>
using namespace std;
/* for the edge with weight value 
 * struct edge{int to, cost;}
 * vector<edge> G[MAX_N];
*/
int main(){
	int V, E;
	vector<int> Graphs[V];
	cin >>V >> E;
	for(int i = 0; i < V; i++){
		int v,t;
		cin >> v >> t;
		Graphs[v].push_back(t);
	}
	return 0;
}

