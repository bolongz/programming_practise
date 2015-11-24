#include<iostream>
#include<string>
using namespace std;
int N;
string S;
string s;
int main(){
	cin >> N;
	S.resize(N);
	s.resize(N);
	for(int i = 0 ; i < N; i++){
		cin >> S[i];
	}
	int a = 0, b = N - 1, k = 0;
	while(a <= b){
		bool left = false;
		for(int i = 0 ; a + i <= b; i++){
			if(S[a + i] < S[b-i]){
				left = true;
				break;
			}else if(S[a+i] > S[b-i]){
				left = false;
				break;
			}
		
		}
		if(left) s[k++] = S[a++];
		else s[k++] = S[b--];
	}
	for(int i = 0 ; i < N ;i++){
		if(i != 0 && i % 80  == 0) {
			cout << endl;
		}
		cout << s[i];
	}
	return 0;
}
