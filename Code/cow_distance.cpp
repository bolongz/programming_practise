#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 100000;
const int INF = 1000000000;

int N = 0;
int M = 0;

double x[MAX_N];
bool C(int d){
	int last = 0;
	for(int i = 1 ; i< M  ; i++){
		int crt = last + 1;
		while(crt < N && (x[crt] - x[last]) < d){
			crt++;
		}
		if(crt == N){
			return false;
		}
		last  = crt;
	}
	return true;
}

int main(){
	cin >> N >> M;
	for (int i = 0 ; i < N ; i++){
		cin >> x[i];
	}
	sort(x, x+N);
	int lb = 0 , ub = INF;
	while(ub - lb > 1){
		int mid = (lb + ub) /2;
		if(C(mid)){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	cout << lb <<endl;
	return 0;
}
