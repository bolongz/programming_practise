/* This is the solution for POJ2395
 * The method used here is kruskal algorithm
 * We should calculate the lagrest cost in the MST
 */



#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAX_N = 2001;
const int MAX_M = 10000;
int par[MAX_N];
int rank[MAX_N];
struct edge{
	int u, v;
	long long  cost;
};
int N, E;
edge e[MAX_N * MAX_N];
int en; // count edge numbers 
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
long long  kruskal(){
	long long  res = 0;
	sort(e, e + E , comp); // sort the edge with the weight value
	initial(N);
	for(int i = 0 ; i < E; i++){
		edge es = e[i];
		if(!same(es.u, es.v)){
			unite(es.u,es.v);
			if(res < es.cost)
				res = es.cost;
		}
	}
	return res;
}

int main(){
	freopen("in.txt", "r", stdin);
	int M;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < M; i++){
			int a, b; long long c;
			scanf("%d %d %lld", &a, &b, &c);
			e[i] = (edge){a, b , c};
	}
	E = M;
	printf("%lld\n", kruskal());
	fclose(stdin);
	return 0;
}
