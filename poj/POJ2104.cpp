#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int B = 1000; 
const int max_n = 100000;
const int max_m = 5000;

int N, M;

vector<int> A(max_n);
vector<int> I(max_m);
vector<int> J(max_m);
vector<int> K(max_m);

int nums[max_n];
vector<int> bucket[max_n / B];

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i <  N; i++){
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &I[i], &J[i], &K[i]);
	}
	for(int i = 0; i < N; i++){
		bucket[i / B].push_back(A[i]);
		nums[i] = A[i];;
	}
	sort(nums, nums + N);
	for(int i = 0; i < N / B; i++){
		sort(bucket[i].begin(), bucket[i].end());
	}
	for(int i = 0 ; i < M; i++){
		int l = I[i], r = J[i] + 1, k = K[i];
		int lb = -1, ub = N-1;

		while (ub - lb > 1){
			int md = (lb + ub) /2;
			int x = nums[md];
			int t1 =l - 1, tr = r - 1, c = 0;
			
			while(t1 < tr && t1 % B!=0) if(A[t1++] <= x) c++;
			while(t1 < tr && tr % B!=0) if(A[--tr] <= x) c++;
			
			while(t1 < tr){
				int b = t1 / B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(),x) - bucket[b].begin();
				t1 += B;
			}
			
			if( c >= k) ub = md;
			else lb = md;
		}
		printf("%d\n", nums[ub]);
	}
	fclose(stdin);
	return 0;
}
	





		









