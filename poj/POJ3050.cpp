#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int pos[10][10];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
string ans;
int a[10];
map<string ,int>m;

void dfs(int x,int y,int cur)
{
	if(cur==6)
	{
		ans.clear();
		for(int i=0;i<6;i++)						
			ans=ans+(char)a[i];
		m[ans]++;
				
		return;
	}

	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||nx>4||ny>4)
			continue;

		a[cur]=pos[nx][ny];
		dfs(nx,ny,cur+1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&pos[i][j]);

	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			a[0]=pos[i][j];
			dfs(i,j,1);
		}

	printf("%d\n",int(m.size()));	
	return 0;
}
