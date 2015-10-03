#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long li;
int main(){
	size_t n;
	cin >> n;
	vector<li> x(n,0);
	vector<li> y(n,0);
	for(int i = 0 ; i < n ;i ++){
		cin >> x[i];
	}
	for(int i = 0 ; i < n ;i ++){
		cin >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += x[i] * y[n-i-1];
	}
	cout << sum << endl;
	return 0;

}
