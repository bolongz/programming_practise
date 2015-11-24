/* This the solution for POJ3069 */
/* The algorithm used here is greedy algorithm */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> res;
	while(true){
		int N, R;
		cin >> R >> N;
		if( N == - 1 && R == -1) break;
		vector<int> P(N);
		for(int i = 0 ; i < N ;i++){
			cin >> P[i];
		}
		sort(&P[0], &P[0] + N);
		int i = 0 , ans = 0;
		while(i < N){
			int s = P[i++];
			while( i < N && P[i] <= s + R) i++;
			int p = P[i-1];
			while(i < N && P[i] <= p + R) i++;
			ans++;
		}
		res.push_back(ans);
	}
	for(int i = 0 ; i < res.size() ; i++){
		cout << res[i] << endl;
	}
	return 0;
	
}
