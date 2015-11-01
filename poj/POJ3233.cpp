#include<stdio.h>
#include<vector>

using namespace std;

const int max_n = 1e9;

typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> matrix;

int M;
matrix mul(matrix &A, matrix&B){
	matrix C(A.size(), vec(B[0].size()));
	for(int i = 0 ; i < A.size() ; i++){
		for(int j = 0 ; j < B.size(); j++){
			for(int k = 0 ; k < B[0].size() ;k++){
				C[i][j] =(C[i][j] + A[i][k] * B[k][j]) %M;
			}
		}
	}
	return C;
}

matrix pow(matrix A, ll n){

	matrix B(A.size(), vec(A.size()));
	for(int i = 0;  i < A.size() ;i++){
		B[i][i] = 1;
	}
	while(n > 0){
		if(n &1) B = mul(B, A);
		A = mul(A, A);
		 n >>= 1;
	}
	return B;
}

int main(){
	int N, K; 
	scanf("%d %d %d", &N, &K, &M);
	matrix A(N, vec(N));
	for(int i =0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	matrix B( N * 2, vec(N * 2));
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < N; j++){
			B[i][j] = A[i][j];
		}
		B[N+i][i] = 1;
		B[N+i][N+i] = 1;
	}
	B = pow(B, K + 1);
	for(int i = 0 ; i < N ;i++){
		for(int j = 0 ;j < N; j++){
			int a = B[N+i][j] % M;
			if( i == j) a = (a + M  -1) %M;
			printf("%d ", a);
		}
		printf("\n");
	}
	return 0;
}
