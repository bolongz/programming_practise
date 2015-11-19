#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAX_N = 20;

char titles[MAX_N][MAX_N];

int W, H;
int n = 0;

//bool counted[MAX_N][MAX_N];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){

	/*if(!counted[x][y] && (titles[x][y] == '@' || titles[x][y] == '.')){
		n++;
		counted[x][y] = true;
	}*/
//	counted[x][y] = '#';
	titles[x][y] = '#';
	n++;
	for(int i = 0; i < 4; i++){
		int _dx = x + dx[i], _dy = y + dy[i];
		if(titles[_dx][_dy] == '.'&& _dx <H && _dy < W && _dx >= 0 && _dy >= 0) dfs(_dx, _dy);
		//if(!counted[_dx][_dy] && titles[_dx][_dy] == '.'&& _dx <H && _dy < W) dfs(_dx, _dy);
	}
	return ;
}

int main(){
	freopen("in.txt", "r", stdin);
	int _i, _j, sign =0;
	while(scanf("%d %d", &W, &H) == 2 && (W != 0 && H!=0)){
		n = 0;sign = 0;
		for(int i = 0 ;i < H; i++){
			for(int j = 0 ; j < W; j++){
				cin >> titles[i][j];
			//	counted[i][j] = false;
				if(titles[i][j] == '@') {sign = 1;_i = i; _j =j;}
			}
		}
		if(sign) dfs(_i, _j);
		cout << n << endl;
	}
	fclose(stdin);
	return 0;
}
