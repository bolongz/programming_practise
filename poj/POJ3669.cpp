/* This is problem is about the mentor shower POJ 3669*/
/* The method used here is BFS */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX_N = 320;
const  int INF = 0x7f7f7f7f;
int meteor[MAX_N][MAX_N];
bool visted[MAX_N][MAX_N];
int N, _min;

int dx[5] = {1, 0 , -1, 0, 0};
int dy[5] = {0, 1 , 0, -1, 0};

struct P{int x, y, t;};

int bfs(){
	queue<P> que;
	P current;
	current.x = 0;
	current.y = 0;
	current.t = 0;
	visted[0][0] = 1;
	que.push(current);
	while(!que.empty()){
		const P p = que.front(); que.pop();
		for(int i = 0 ; i< 4; i++){
			current = p;
			current.x = current.x + dx[i];
			current.y = current.y + dy[i];
			++current.t;
			if(current.x >= 0 && current.y >= 0 && meteor[current.x][current.y] > current.t && !visted[current.x][current.y]){
					visted[current.x][current.y] = true;
					if(meteor[current.x][current.y] == INF){
						return current.t;
					}
				que.push(current);
			}
		}
	}
	return -1;
}

int main(){

	freopen("in.txt", "r", stdin);
	memset(visted, 0, sizeof(visted));
	memset(meteor, INF, sizeof(meteor));
	int ai, aj, t;
	scanf("%d", &N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d %d", &ai, &aj, &t);
		for(int j = 0; j < 5 ; j++){
			int _dx = ai + dx[j];
			int _dy = aj + dy[j];
			if(_dx >= 0 && _dy >= 0 && meteor[_dx][_dy] > t){
				meteor[_dx][_dy] = t;
			}
		}
	}
	if(meteor[0][0] == 0) puts("-1");
	else if(meteor[0][0] == INF) puts("0");
	else printf("%d\n", bfs());
	fclose(stdin);
	return 0;
}

