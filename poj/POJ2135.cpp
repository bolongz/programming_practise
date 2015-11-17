#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stdio.h>
const int EPS = 1e-10;
using namespace std;
const int MAX_N = 13;
double add(double a, double b){
	if(abs(a + b) < EPS * (abs(a) + abs(b) ) ) return 0;
	return a + b;
}

struct P{
	double x, y;
	P(){};
	P(double x, double y):x(x), y(y){};
	P operator +(P p){return P(add(x, p.x), add(y, p.y));}
	P operator -(P p){ return P(add(x, -p.x), add(y, -p.y));}
	P operator *(double d){return P(x * d, y * d);}
	double dot(P p){ return add(x*p.x, y*p.y);}
	double det(P p){return add(x * p.y, -y * p.x);}
};

bool on_seg(P p1, P p2, P q){
	return (p1 - q).det(p2-q) == 0 && (p1 - q).dot(p2 -q) <= 0;
}

P intersection(P p1, P p2, P q1, P q2){
	return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2-p1));
}

int main(){
	freopen("in.txt", "r", stdin);
	while(true){
		int n ;
		P p[MAX_N], q[MAX_N];
		int a[MAX_N], b[MAX_N];
		bool g[MAX_N][MAX_N]; 
		scanf("%d", &n);
		int index = 0;
		if ( n == 0) break;
		while(true){
			for(int i = 0 ; i < n ; i++){
				scanf("%lf %lf %lf %lf", &p[i].x, &p[i].y, &q[i].x, &q[i].y);
			}
			int _a, _b;
			while(scanf("%d %d", &_a, &_b) == 2 && (_a != 0 && _b!=0)){
				a[index] = _a;
				b[index] = _b;
				index++;
			}
			break;
		}
		for(int i = 0 ;i < n ;i ++){
			g[i][i] = true;
			for(int j = 0 ; j < i; j++){
				if((p[i]- q[i]).det(p[j] - q[j]) == 0){
					g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j])
									|| on_seg(p[i], q[i], q[j])
									|| on_seg(p[j], q[j], p[i])
									|| on_seg(p[j], q[j], q[i]);
				}else{
					P r = intersection(p[i], q[i], p[j], q[j]);
					g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
				}
			}
		}
		for(int k = 0 ; k < n ; k++){
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < n ;j++){
					g[i][j] |= g[i][k] && g[k][j];
				}
			}
		}
		for(int i = 0; i < index ; i++){
//			if(g[a[i] - 1][b[i] - 1]) cout << "CONNECTED" << endl;
//			else cout << "NOT CONNECTED" << endl;;
			puts(g[a[i] - 1][b[i] - 1] ? "CONNECTED": "NOT CONNECTED");
		}
	}
	fclose(stdin);
	return 0;
}

				
