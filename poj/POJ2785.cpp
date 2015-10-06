#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int max_n = 4000;

int main(){
	vector<int> A(max_n);
	vector<int> B(max_n);
	vector<int> C(max_n);
	vector<int> D(max_n);
	int n;
	scanf("%d", &n);
	vector<int> E(n*n);
	for(int i =0 ; i < n ; i++){
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
		scanf("%d", &C[i]);
		scanf("%d", &D[i]);
	}
	for(int  i= 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			E[i * n + j] = C[i] + D[j];
		}
	}
	sort(E.begin(), E.end());
	long long int res = 0;
	for(int  i= 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int d = -(A[i] + B[j]);
			res = res + upper_bound(E.begin(), E.end(), d) - lower_bound(E.begin(), E.end(), d);
		}
	}
	printf("%lld\n", res);
	return 0;
}
