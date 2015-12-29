#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX_N= 1000;
const double INF = 1000000000.0;
int N, K;
int a[MAX_N];
int b[MAX_N];
double y[MAX_N];
bool C(double x){
	for(int i = 0 ;i < N; i++){
		y[i] =   a[i] - x * b[i];
	}
	sort(y, y +N, greater<int>());
	double sum = 0 ;
	for(int i = 0 ; i < N - K; i++){
		sum += y[i];
	}
	return sum >= 0;
}
int main(){
	freopen("in.txt", "r", stdin);
	while(scanf("%d %d", &N, &K) == 2 && (N || K)){
		for(int i = 0 ; i < N ; i++) scanf("%d", &a[i]);
		for(int i = 0 ; i < N ; i++) scanf("%d", &b[i]);
		double lb = 0.0, ub = 1.0;
//		for(int i = 0 ; i < 100; i++){
		while(abs(ub - lb) > 0.00001){
			double mid = (lb +ub) /2.0;
			if(C(mid)) lb = mid;
			else ub = mid;
		}
		int ans = int(100 * ub +0.5);
		printf("%d\n", ans );
	}
	return 0;
}

