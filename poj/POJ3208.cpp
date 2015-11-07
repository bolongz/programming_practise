#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct edge{
	int to, cap, rev;
};

const int INF = 1 << 20;
const int MAX_N = 100;
const int MAX_V = 4 * MAX_N + 2;
int N, F, D;
typedef vector<bool> vec;
vector<edge> G[MAX_V];
vec used(MAX_V);
vector<vec> likeF(MAX_N, vec(MAX_N));
vector<vec> likeD(MAX_N, vec(MAX_N));
void add_edge(int from, int to, int cap){
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size() -1});
}
int dfs(int v, int t, int f){
	if( v == t) return f;
	used[v] = true;
	for(int i = 0 ; i < G[v].size(); i++){
		edge &e = G[v][i];
		if(!used[e.to] && e.cap > 0){
			int d = dfs(e.to, t, min(f,e.cap));
			if(d > 0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s, int t){
	int flow = 0;
	for(;;){
		for(int i = 0; i < MAX_V; i++){
			used[i] = false;
		}
		int f = dfs (s, t, INF);
		if ( f == 0) return flow;
		flow += f;
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &N, &F,&D);
	int c, f;
	for(int i = 0; i < likeF.size(); i++){
		for(int j = 0; j < likeF[0].size();j++){
			likeF[i][j] = false;
			likeD[i][j] = false;
		}
	}
	int index = 0;
	while(scanf("%d %d", &c, &f) == 2){
		int v;
		while(c > 0){
			scanf("%d", &v);
			likeF[index][v-1] = true;
			c--;
		}
		while(f > 0){
			scanf("%d", &v);
			likeD[index][v-1] = true;
			f--;
		}
		index++;
	}
	int s = N * 2 + F + D, t = s + 1;
	for(int i = 0; i < F; i++){
		add_edge(s, N * 2 + i, 1);
	}
	for(int  i = 0 ; i < D; i++){
		add_edge(N * 2 + F + i, t, 1);
	}
	for(int i = 0 ; i < N; i++){
		add_edge(i, N + i, 1);
		for(int j = 0; j < F; j++){
			if(likeF[i][j]) add_edge(N * 2 + j, i, 1);
		}
		for(int j = 0; j < D; j++){
			if(likeD[i][j]) add_edge(N + i, N * 2 + F + j, 1);
		}
	}
	printf("%d\n", max_flow(s, t));
	fclose(stdin);
	return 0;
}
