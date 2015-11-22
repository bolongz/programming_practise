#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAX_N = 105;
int par[MAX_N];
int rank[MAX_N];
int cost[MAX_N][MAX_N];
const int INF = 200000;
struct edge{
	int u, v, cost;
};
int N, E;
edge e[MAX_N * MAX_N];

//initial the disjoint set;
void initial(int n){
	for(int i=0; i < n; i++){
		par[i] = i;
		rank[i] = 0;
	}
}
//find the root of the tree and make 
// the leaves connect to the root directly
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		par[x] = find(par[x]);
		return par[x];
	}
}
//unite two trees
void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
}
//same

bool same(int x, int y){
	return find(x) == find(y);
}

bool comp(const edge &e1, const edge &e2){
	return e1.cost < e2.cost;
}
int kruskal(){
	int res = 0;
	sort(e, e + E , comp); // sort the edge with the weight value
	initial(N);
	for(int i = 0 ; i < E; i++){
		edge es = e[i];
		if(!same(es.u, es.v)){
			unite(es.u,es.v);
			res += es.cost;
		}
	}
	return res;
}

int main(){
	freopen("in.txt", "r", stdin);
	while( scanf("%d", &N) == 1){;
		int id = 0;
		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < N ;j++){
				int w;
				scanf("%d", &w);
				if( i != j ){
					e[id++] = (edge){i, j , w};
				}

			}
		}
		E = id;
		printf("%d\n", kruskal());
	}
	fclose(stdin);
	return 0;
}
