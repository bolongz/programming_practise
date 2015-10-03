#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 10000;
const int MAX_K = 10000;
const int INF = 1000000;

int w[MAX_N];
int v[MAX_N];

double y[MAX_N];

int N;
int K;

bool C(double x){
	double sum = 0;
	for(int i = 0 ; i < N ; i++){
		y[i] = v[i] - x*w[i];
	}
	sort(y, y + N);
	for(int i = 0 ; i< K ; i++){
		sum += y[N-i-1];
	}
	return sum >= 0;
}
int main(){
	cin >> N >> K;
	for(int i = 0 ; i < N ; i++){
		cin >> w[i] >> v[i];
	}
	double lb = 0 , ub = INF;
	for(int i = 0 ; i < 100 ; i++){
		double mid = (lb + ub) /2;
		if(C(mid)){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	cout << lb << endl;
	cout << ub << endl;
	return 0;
}
