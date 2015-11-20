/* This is the program for POJ 3009.*/
/* dfs has been used in this program*/


#include<iostream>
#include<stdio.h>

using namespace std;

const int MAX_N = 20;
const int MAX = 9999999;
int	ei, ej, _min, si, sj;
int w, h, steps = 0;
int stone[MAX_N][MAX_N];

const int dx[4]= {0, 1, 0, -1};
const int dy[4]= {1, 0, -1, 0};

void dfs(const int x, const int y){
	if(steps >= 10) return;
	for(int i = 0 ; i < 4 ; i++){
		int _dx = x, _dy = y;
		while(true){
			_dx += dx[i];
			_dy += dy[i];
			if(_dx >= h || _dy >= w || _dx < 0 || _dy < 0) break ; // if hit the bound then break and choose other direction
			if(_dx == ei && _dy == ej){
				steps ++;
				if( _min > steps ) _min = steps; // hit the end points and update the min steps
				steps --;
				return;
			}else if(stone[_dx][_dy] == 1){ // hip the block
				if( _dx - dx[i] != x || _dy - dy[i] != y){
					stone[_dx][_dy] = 0; // make the block disappear
					steps++;
					dfs(_dx - dx[i], _dy - dy[i]);
					stone[_dx][_dy] = 1; // reset the block 
					steps --; // sub one from the steps
				}
				break;
			}
		}
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	while(scanf("%d %d", &w, &h) == 2 && w != 0 && h != 0){
		for(int i = 0 ; i < h ; i++){
			for(int j = 0 ; j < w ; j++){
				scanf("%d", &stone[i][j]);
				if(stone[i][j] == 2) {	
					si = i;
					sj = j;
				}
				if(stone[i][j] == 3) {	
					ei = i;
					ej = j;
				}
			}
		}
		_min = MAX;
		steps = 0;
		dfs(si,sj);
		if(_min == MAX) puts("-1");
		else printf("%d\n", _min);
	}
	fclose(stdin);
	return 0;
}
