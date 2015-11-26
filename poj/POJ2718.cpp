/* This the solution for POJ 2718 
 * the method used here is search method
 */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int N;
const int INF = 1 << 20;
int d[10];

int minn, maxn = INF;
int main(){
		
	freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	for(int i = 0 ; i < N ;i++){
		char c; int index = 0;
		while(true){
			scanf("%d%c", &d[index++], &c);
			if(c != ' ') break;
		}
		if( index == 2) {
			printf("%d\n", abs(d[0] - d[1]));
			continue;
		}
		while(d[0] == 0) next_permutation(d, d + index); // cut some useless permutation
		minn = maxn;	
		do{
			if(d[index/2]){ // cut some permutation, which will get the same result as others
				int x = 0 ,y = 0;
				for(int i = 0; i < index /2 ; i++) x = x * 10 + d[i];
				for(int i = index /2 ; i < index; i++) y = y * 10 + d[i];
				minn = min(abs( x - y), minn);
			}
		}while( next_permutation(d, d + index));
		printf("%d\n", minn);
	}
	return  0;
}
