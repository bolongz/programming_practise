#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int ST_SIZE = (1 << 18) -1;

const int B = 1000; 
const int max_n = 100000;
const int max_m = 5000;

int N, M;

vector<int> A(max_n);
vector<int> I(max_m);
vector<int> J(max_m);
vector<int> K(max_m);

int nums[max_n];

vector<int> dat[ST_SIZE];

void init(int k , int l , int r){ // [l, r);
	if(r - l == 1){
		dat[k].push_back(A[l]);
	}else{
		int lch = 2 * k + 1, rch = 2 * k + 2;
		init(lch, l, (l + r)/2);
		init(rch, (l + r)/2, r);
		dat[k].resize(r - l);
		merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
	}
}
		
int query( int i, int j, int x, int k ,int l, int r){
	if(j <= l || i >= r){
		return 0;
	}else if( i <= l && j >= r){
		return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
	}else{
		int lc = query(i,j ,x, k * 2 + 1, l, (l + r) /2);
		int rc = query(i,j, x, k * 2 + 2, (l + r) /2, r);
		return lc + rc;
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i <  N; i++){
		scanf("%d", &A[i]);
		nums[i] = A[i];;
	}
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &I[i], &J[i], &K[i]);
	}
	sort(nums, nums + N);
	init(0, 0, N);
	for(int i = 0 ; i < M; i++){
		int l = I[i] - 1, r = J[i], k = K[i];
		int lb = -1, ub = N-1;

		while (ub - lb > 1){
			int md = (lb + ub) /2;
			int x = nums[md];
			int c = query(l, r, x, 0, 0, N);	
			if( c >= k) ub = md;
			else lb = md;
		}
		printf("%d\n", nums[ub]);
	}
	fclose(stdin);
	return 0;
}
