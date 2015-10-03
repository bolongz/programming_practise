#include<iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y){
	if( b == 0){
		x = 1;
		y = 0; 
		return a;
	}
	int d = exgcd(b, a%b, x, y);
	int t = x;
	x = y;
	y = t - (a/b) * y;
	return d;
}
int main(){
	int a, b;
	cin >> a >> b;
	int x, y;
	int g = exgcd(a, b, x, y);
	cout << g <<" " <<  x << " " <<  y <<   endl;
	return 0;
}
