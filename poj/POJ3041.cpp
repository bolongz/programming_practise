#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<stdlib.h>
using namespace std;
const int max_n = 500;
const int max_k = 10000;
const int max_v = 1000;
int N, K;
int V;
vector<int> R(max_k);
vector<int> C(max_k);
vector<int> G[max_v];
vector<int>  match(max_v, -1);
vector<bool> used(max_v, false);;

void add_edge(int u, int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v){
	used[v] = true;
	for(int i = 0 ; i < G[v].size(); i++){
		int u = G[v][i], w = match[u];
		if( w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int bit_matching(){
	int res = 0;
	for(int v = 0; v < V; v++){
		for(int i = 0; i < V; i++) used[i] =false;
		if(match[v] < 0){
			if(dfs(v)){
				res++;
			}
		}
	}
	return res;
}
int main(){
	freopen("in.txt","r", stdin);
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < K ;i++){
		scanf("%d %d", &R[i], &C[i]);
	}
	V = 2 * N;
	for(int i = 0 ; i < K; i++){
		add_edge(R[i] -1, N + C[i] - 1);
	}
	printf("%d\n", bit_matching());
	fclose(stdin);
	return 0;
}
