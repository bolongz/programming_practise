#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;

class cor{
public:
	int x, y;
};

const int MAX_N = 1001;
int par[MAX_N];
int rank[MAX_N];
double dis[MAX_N][MAX_N];

int N,  D;
cor loc[MAX_N];
bool _fixed[MAX_N];
void initial(int n){
	for(int i=0; i < n; i++){
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		par[x] = find(par[x]);
		return par[x];
	}
}
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
bool same(int x, int y){
	return find(x) == find(y);
}
double _distance(const cor &a, const cor &b){
	return sqrt(double((a.x - b.x) * (a.x - b.x)) + double((a.y - b.y) * (a.y - b.y)));
}

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &D);
	initial(N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d", &loc[i].x, &loc[i].y);
	}
	memset(_fixed, 0, sizeof(_fixed));
	memset(dis, 0, sizeof(dis));

	for(int i = 0; i < N ; i++){
		for(int j = i + 1 ; j < N; j++){
			dis[j][i] = dis[i][j] = _distance(loc[i], loc[j]);
		}
	}
		char c; int id;
	while(scanf(" %c ", &c) == 1 ){
		if( c != 'O' && c != 'S') break;
		if( c == 'O'){
			scanf("%d", &id);
			_fixed[id - 1] = true;
			for( int i = 0; i < N ;i++){	
				if( i != id - 1 && _fixed[i] == true && dis[id - 1][i] <=double(D)){
					unite(i, id - 1);
				}
			}
		}
		if( c == 'S') {
			int x, y;
			scanf("%d %d", &x, &y);
			if(same(x - 1, y - 1)){
					printf("SUCCESS\n");
			}else{
				printf("FAIL\n");
			}
		}
	}
	fclose(stdin);
	return 0;
}
