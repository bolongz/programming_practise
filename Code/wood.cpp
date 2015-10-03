#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> L;
	L.resize(N);
	for(int i = 0; i < N ;i++){
		cin >> L[i];
	}
	int result = 0;
	int result_last = 0;
	int small = 0;
	while(N > 1){
		sort(L.begin(),L.end());
		small = L[0] + L[1];
		result = small + result_last;
		result_last = result;
		L[1] = small;
		L.erase(L.begin());
		--N;
	}
	cout << result << endl;
	return 0;
}
