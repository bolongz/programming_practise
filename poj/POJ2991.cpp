#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846

using namespace std;
const int st_size = (1 << 15) -1;
const int max_n = 10000;
int N, C;
vector<int> L(max_n);
vector<int> S(max_n);
vector<int> A(max_n);

vector<double> vx(st_size); //vector data
vector<double> vy(st_size); // vector data
vector<double> ang(st_size); // angle daata

vector<double> prev(max_n); // deposite the angle data

void init(int k, int l, int r){
	ang[k] = vx[k] = 0.0;
	if(r - l == 1){
		vy[k] = L[l];
	}else{
		int chl = k * 2 + 1, chr = k * 2 + 2;
		init(chl,l, (l + r) /2);
		init(chr,(l + r) /2, r);
		vy[k] = vy[chl] + vy[chr];
	}
}

void change(int s, double a, int v, int l, int r){
	if(s <= l) return;
	else if(s < r){
		int chl = v * 2 + 1, chr = v * 2  + 2;
		int m = (l + r ) / 2;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if( s <= m) ang[v] += a;
		double s1 = sin(ang[v]), c = cos(ang[v]);
		vx[v] = vx[chl] + (c * vx[chr] - s1 * vy[chr]);
		vy[v] = vy[chl] + (s1 * vx[chr] - c * vy[chr]);
	}
}

int main(){
/*	vector<vector<double> > fx;
	vector<vector<double> > fy;
	vector<double> x;
	vector<double> y;
	int c = 0;
*/	//freopen("in.txt","r", stdin);
    freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
	while(scanf("%d %d", &N, &C) == 2 ){
//		scanf("%d %d", &N, &C);
		for(int  i =0 ;i < N; i++){
				scanf("%d", &L[i]);
		}
		for(int  i =0 ;i < C; i++){
				scanf("%d", &S[i]);
		}
		for(int  i =0 ;i < C; i++){
			scanf("%d",&A[i]);
		}
		
		init(0, 0, N);
		for(int i = 1; i < N; i++) prev[i] = M_PI;
		for(int  i = 0; i < C; i++){
			int s = S[i];
			double a  = A[i] / 360.0 * 2 * M_PI;
			change (s, a -prev[s], 0, 0, N);
			prev[s] = a;
			printf("%.2f %.2f\n", vx[0], vy[0]);
//			x.push_back(vx[0]);
//			y.push_back(vy[0]);
		}
//		fx.push_back(x);
//		fy.push_back(y);
		printf("\n");
	}
/*	for(int i = 0 ; i< fx.size(); i++){
		for(int j = 0 ; j < fx[i].size(); j++)
			cout << fx[i][j] << " " << fy[i][j];
		cout << endl;
	}
*///	fclose(stdin);
		fclose(stdin);
		fclose(stdout);
	return 0;
}



