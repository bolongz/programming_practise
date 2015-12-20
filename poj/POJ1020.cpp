#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;

int t, s, n;

int len[160]; // represent the total cube size in the i row.
int seg[15];

bool dfs(int index){
	if(index == n) return true;
	int _min = 10000000;
	int pos = 0;
	for(int i = 1; i <= s ; i++){
		if(_min > len[i]){
			_min = len[i];
			pos = i;
		}
	}
	for(int  i = 1; i <= 10; i++){
		if(seg[i]){
			if(len[pos] + i <= s){
				int width = 0;
				for(int j = pos; j <= s; j++)
					if(len[j] == len[pos]) width++;
					else break;
				if(width >= i){
					seg[i]--;
					for(int j = pos; j < pos + i; j++)
						len[j] += i;
					if(dfs(index + 1)) return true;
					seg[i]++;
					for(int j = pos; j < pos + i; j++)
						len[j] -= i;
				}
			}

		}	
	}
	return false;
}
				
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while(t--){
		int area = 0;
		scanf("%d %d", &s, &n);
		memset(len, 0, sizeof(len));
		memset(seg, 0, sizeof(seg));
		for(int i = 1 ; i <= n; i++){
			int a;
			scanf("%d", &a);
			area += a * a;
			seg[a]++;
		}
		if( area == s * s && dfs(0)){
			printf("KHOOOOB!\n");
		}else{
			printf("HUTUTU!\n");
		}
	}
	return 0;
}
			

