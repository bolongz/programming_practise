#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAX_V = 20000;
const int MAX_R = 50000;
const int MAX_E = 50000;
int par[MAX_V];
int rank[MAX_V];

struct edge{
	int u, v, cost;
};
int N, M, R;
int V;
edge e[MAX_E];

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
	sort(e, e+R, comp); // sort the edge with the weight value
	initial(V);
	for(int i = 0 ; i < R ; i++){
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
	int times;
	scanf("%d", &times);
	for(int k = 0 ; k < times; k++){
		scanf("%d %d %d", &N, &M, &R);
		V = N + M;
		int x[MAX_R], y[MAX_R], z[MAX_R];
		for(int i = 0 ;  i < R ; i++){
			scanf("%d %d %d", &x[i], &y[i], &z[i]);
		}
		for(int  i= 0 ; i < R; i++){
			e[i] = (edge){x[i], N+y[i], -z[i]};
		}
		cout << 10000 * (N + M) + kruskal() << endl;
	}
		fclose(stdin);
	return 0;
}
