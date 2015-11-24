/* This is sulution for POJ2431*/
#include<iostream>
#include<queue>
#include<vector>
#include <utility>
#include<algorithm>
using namespace std;

int main(){
	int L, P, N;
	
	vector<int> A;
	vector<int> B;
	cin >> N;
	A.resize(N + 1);
	B.resize(N + 1);
	pair<int, int> p[10001];
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
		cin >> B[i];
	}
	cin >> L >> P;
	for(int i = 0 ; i < N; i++){
		p[i].first = L - A[i];
		p[i].second = B[i];
	}
	p[N].first = L;
	p[N].second = 0;
	sort(p, p+N+1);
//	for(int i = 0 ; i <= N; i++){
//		cout << p[i].first  << " " << p[i].second << endl;;
//	}
	N++;
	bool cannotreach = false;
	priority_queue<int> que;
	int ans = 0 , pos = 0, tank = P;
	for( int i = 0 ; i < N; i++){
		int d = p[i].first  - pos;
		while( tank - d < 0){
			if(que.empty()){
				cout << -1 << endl;
				return 0;
			}
			tank += que.top();
			que.pop();
			ans++;
		}
		tank -= d;
		pos = p[i].first;
		que.push(p[i].second);
	}
	cout << ans << endl;
	return 0;
}
