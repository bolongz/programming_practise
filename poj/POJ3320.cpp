#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stdio.h>
using namespace std;

const int max_n = 1000000;

int main(){
	vector<int> a(max_n);
	int p;
	scanf("%d", &p);
	set<int> all;
	for (int i = 0 ; i < p ; i++){
		scanf("%d", &a[i]);
		all.insert(a[i]);
	}
	int n = all.size();
	int num = 0, s = 0, t = 0, res = max_n + 1;
	map<int, int> count;
	for(;;){
		while(t < p && num < n){
			if(count[a[t++]]++ == 0){
				num ++;
			}
		}
		if( num < n) break;
		res = min(res, t - s);
		if(--count[a[s++]]  == 0){
			num--;
		}
	}
	printf("%d\n", res);
	return 0;
}
