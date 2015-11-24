#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
	const int maxN = 1000000;
	int c, n, L;
	cin >> c ; 
	vector<int> minT(c);
	vector<int> maxT(c);
	vector<vector<int> > x(c);
	for( int i  = 0 ; i < c ; i++){
	
		cin >> L >> n;
		for(int j = 0 ; j < n; j++){
			x[i].resize(n);
		}
	
		for(int  j = 0 ; j < n ; j++){
		 	cin >> x[i][j]	;	
		}
		for(int j = 0 ; j < n ; j++){
			minT[i] = std::max(minT[i], std::min(x[i][j], L-x[i][j]));
			maxT[i] = std::max(maxT[i], std::max(x[i][j],L-x[i][j]));
		}
	}
	for(int i = 0 ; i < c ; i++)
		cout << minT[i] << " " << maxT[i] << endl;
	return 0;
}
