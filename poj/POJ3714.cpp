/* This is the solution for POJ3714 */
/* The method used here is divide and conquer */
/* closest points */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
const int MAX_N = 200010;
int N;

const double MAX_DIST = 1e100;
struct Points{
	double x, y;
	bool flag;
};
inline double dist(const Points &a, const Points &b){

	if(a.flag != b.flag){
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}else{
		return MAX_DIST;
	}
}

Points pt[MAX_N];
int temp[MAX_N];

inline bool x_cmp(const Points &a, const Points &b){
	return a.x < b.x ;
}

inline bool y_cmp(const int a, const int b){
	return pt[a].y < pt[b].y ;
}

double closest_pair(int left, int right){
		
	if( right - left == 1) {
		return dist(pt[left], pt[right]);
	}else if(right - left == 2){
		return min(min(dist(pt[left], pt[left+1]), dist(pt[left], pt[left+2])),dist(pt[left+1], pt[left+2]));
	}
	int mid = (left + right) >> 1;
	double _min = min(closest_pair(left, mid), closest_pair(mid + 1, right));
	if(_min == 0) return 0;
	int yn = 0;
	for(int i = mid; i >= left && pt[mid].x - pt[i].x < _min; i --){
		temp[yn++] = i;
	}
	int ymd = yn;
	for( int i = mid + 1; i <= right && pt[i].x - pt[mid].x < _min; i++){
		temp[yn++] = i;
	}
	for(int i = 0; i < ymd; ++i) 
		for(int j = ymd; j < yn; ++j)
		        _min = min(_min, dist(pt[temp[i]], pt[temp[j]]));
	return _min;
}

int main(){

	freopen("in.txt", "r", stdin);
	int M;
	scanf("%d", &M);
	for(int i = 0 ; i < M; i++){
		scanf("%d", &N);
		for(int j = 0; j < N; j++){
			scanf("%lf %lf", &pt[j].x, &pt[j].y);
			pt[j].flag = false;
		}
		for(int j = N; j < 2 * N; j++){
			scanf("%lf %lf", &pt[j].x, &pt[j].y);
			pt[j].flag = true;
		}
		sort(pt, pt + 2 * N, x_cmp);
		printf("%.3f\n", closest_pair(0, 2 * N -1));
	
	}
	fclose(stdin);
	return 0;
}
				



