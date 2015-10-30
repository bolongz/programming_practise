#include<stdio.h>
#include<vector>

using namespace std;

const int max_n = 1e9;

typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> matrix;

matrix mul(matrix &A, matrix&B){
	matrix C(A.size(), vec(B[0].size()));
	for(int i = 0 ; i < A.size() ; i++){
		for(int j = 0 ; j < B.size(); j++){
			for(int k = 0 ; k < B[0].size() ;k++){
				C[i][j] =(C[i][j] + A[i][k] * B[k][j]) % 10007;
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
	int N; 
	scanf("%d", &N);
	vec a;
		int m;
	for(int i = 0 ; i< N; i++){
		scanf("%d", &m);
		a.push_back(m);
	}
	for(int i =0; i < N; i++){
		matrix A( 3, vec(3));
		A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
		A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;
		A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;
		A = pow(A, a[i]);
		printf("%d\n", A[0][0]);
	}
	return 0;
}
