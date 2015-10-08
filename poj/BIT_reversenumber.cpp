#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int max_n = 100000;

vector<int> a(max_n);
vector<int> bit(max_n+ 1);

int n;

int sum(int i){
	int s = 0;
	while( i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, int x){
	while(i <= n ){
		bit[i] += x;
		i += i& -i;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= n; i++){
		bit[i] = 0;
	}
	int ans = 0;
	for(int j = 0 ; j < n; j++){
		ans += j - sum(a[j]);
		add(a[j], 1);
	}
	printf("%d\n", ans);
	return 0;
}
