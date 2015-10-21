#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

typedef long long int ll;

const int max_n = 100000;
int N, Q;
vector<int> A(max_n + 1);
vector<char> T(max_n);
vector<int> L(max_n);
vector<int> R(max_n);
vector<int> X(max_n);

vector<long long int> bit0(max_n + 1);
vector<long long int> bit1(max_n + 1);

ll sum (vector<ll> &b, int i){
	ll s = 0;
	while(i > 0){
		s += b[i];
		i -= i & -i;
	}
	return s;
}

void add(vector<ll> &b, int i, int v){
	while(i <=N){
		b[i] += v;
		i += i & -i;
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &Q);
//	cout << N << " " << Q << endl;
	for(int  i =1 ; i <= N ;i ++){
		scanf("%d", &A[i]);
	}
	for(int i = 1;  i <= N; i++){
		add(bit0, i, A[i]);
	}
	for(int i = 0 ; i< Q; i++){
	//	cin >> T[i];
		scanf(" %c ", &T[i]);
		if( T[i] == 'C'){
			scanf("%d %d %d", &L[i], &R[i], &X[i]);
		}else{
			scanf("%d %d", &L[i], &R[i]);
		}
	}
		for(int i = 0 ; i < Q; i++){
			if(T[i] == 'C'){
				add(bit0, L[i], -X[i] * (L[i] -1));
				add(bit1, L[i], X[i]);
				add(bit0, R[i] + 1, X[i] * R[i]);
				add(bit1, R[i] + 1, -X[i]);
			}else{
				ll res = 0;
				res += sum(bit0, R[i]) + sum(bit1, R[i]) * R[i];
				res -= sum(bit0, L[i] - 1) + sum(bit1, L[i] -1) * (L[i] -1);
				printf("%lld\n", res);
			}
		}
	fclose(stdin);
	return 0;
}
