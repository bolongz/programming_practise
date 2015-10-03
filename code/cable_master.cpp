#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX_N = 10000;
const int MAX_K = 10000;
const int INF = 110000;
int K = 0;
int N = 0;
double L[MAX_N];

bool C(double x){
	double num = 0;
	for (int i = 0 ; i< N ;i++){
		num += int(L[i] / x);
	}
	return num >= K;
}

int main(){
	cin >> N >> K;
	for(int i = 0 ; i < N ; i++){
		cin >> L[i];
	}
	double lb = 0 , ub = INF;
	for(int  i = 0 ; i < 100 ; i++){
		double min = (lb+ ub) /2;
		if(C(min)){
			lb = min;
		}else{
			ub = min;
		}
	}
	cout << floor(ub * 100) / 100 << endl;
	return 0;
}
