#include<iostream>
#include<vector>
using namespace std;
const int MAX_V = 1000;
int color[MAX_V] = {0};
vector<int> G[MAX_V];

bool dfs(int v, int c){
	color[v] = c;
	for(int i = 0; i < G[v].size(); i++){
		if(color[G[v][i]] == c) return false;
		if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
	}
	return true;
}
int main(){
	int V, E;
	cin >> V >> E;
	for(int i = 0 ; i < E ;i++){
		int v, e;
		cin >> v >> e;
		G[v].push_back(e);
		G[e].push_back(v);
	}
	for(int i = 0 ; i < V; i++)
		if(color[i] == 0){
			if(!dfs(i,1)){
				cout << "No" <<endl;
				return 0;
			}
		}
	cout <<"yes" <<endl;

	return 0;
}
