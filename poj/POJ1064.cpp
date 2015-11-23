/* This the solution for POJ 1064 */
/* The method used here is the binary search */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
const int MAX_N = 10000;
const double INF = 100001.0;
int N, K;
double length[MAX_N];

bool suitable(double l){
	int sum = 0;
	for(int i = 0 ; i < N; i++){
		sum += int(length[i] / l);
	}
	return sum >= K;
}
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for(int i = 0;  i < N ; i++){
		scanf("%lf", &length[i]);
	}
	double lu = 0.0, lh = INF;
	for(int i = 0 ;i < 100; i++){
		double mid = (lu + lh) / 2;
		if(suitable(mid)) lu = mid;
		else lh = mid;
	}
	printf("%.2f\n", floor(lh * 100) / 100);
	fclose(stdin);
	return 0;
}
