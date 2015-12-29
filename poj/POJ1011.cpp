#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int sticks[65];
int used[65];
int N, num = 0, len;
int total = 0;
int sum = 0, u = 0;
bool flag = false;;
void dfs(int us, int current, int l){ // us is the deep for the dfs, current lenght, l is the current length 
	if(flag)  // flag to complete the program
		return;
	if( current == 0){ 
		int k = 0 ;
		while(used[k])k++;
		used[k] = true;
		dfs(us + 1, sticks[k], k+1);
		used[k] = false;
		return ;
	}
	if(current == len){
		if( us == N) flag = true;
		else dfs(us, 0, 0);
		return;
	}
	for( int i = l ; i <N; i++){
		if(!used[i] && sticks[i] +current <= len){
			if(!used[i - 1] &&sticks[i] == sticks[i-1]) continue;
			used[i] = true;
			dfs(us + 1, current +sticks[i], i+1);
			used[i] = false;
		}
	}
}
int main(){
	freopen("in.txt", "r", stdin);
	while(true){
		total = 0;
		scanf("%d", &N);
		if(N == 0) break;
		for(int i = 0 ; i <N ;i++){
			scanf("%d", &sticks[i]);
			total += sticks[i];
		}
		sort(sticks, sticks +N, greater<int>());
		for(int i = total; i >= 1; i--){
			u = 0;
			flag = false;
			len = total / i;
			if(total % i == 0 && len >= sticks[0]){
				memset(used, 0, sizeof(used));
				dfs(0, 0, 0);
				if(flag) break;
			}
		}
		printf("%d\n", len);
	}
	return 0;
}
