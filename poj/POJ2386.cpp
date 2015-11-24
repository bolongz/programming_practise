#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> w;
int N, M;
void dfs_water(int x, int y){
	w[x][y] = '.';
	for (int dx = -1 ; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			int nx = x + dx; int ny = y + dy;
			if(nx >= 0 && nx < N && ny >= 0 && ny < M && w[nx][ny] == 'W') dfs_water(nx,ny);
		}
	}
	return;
}
int main(){
	cin >> N >> M;
	int res = 0;
	w.resize(N);
	for(int i = 0 ; i < N; i++){
		cin >> w[i] ;
	}
	for(int i = 0 ; i < N ;i++){
		for(int j = 0 ; j < M ;j++){
			if(w[i][j] == 'W'){
				dfs_water(i,j);
				res ++;
			}
		}
	}
	cout << res <<endl;
}
