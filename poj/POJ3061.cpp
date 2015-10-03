#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
const int max_n = 100000;
int main(){
	vector<int> a(max_n);
	int n , S;
	scanf("%d %d", &n,&S);
	for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
	}
	int res = n + 1, t = 0, s = 0 , sum = 0;
	while(true){
		while(t < n &&sum < S){
			sum +=a[t++];
		}
		if(sum < S) break;
		res = min(res, t-s);
		sum -= a[s++];
		if( t == s) break;
	}
	if(res > n){
		res = 0;
	}
	printf("%d\n", res);
	return 0;
}

