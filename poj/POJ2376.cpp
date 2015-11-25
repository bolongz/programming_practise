/* This the solution for POJ2376 
 * Greedy algorithm will be used here
 * */

#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
struct node
{
    int start, end;
};

node a[25001];
 
bool cmp(node x, node y)
{
    if (x.start != y.start)
        return x.start < y.start;
    else
        return x.end > y.end;
}
 
int t, n;
 
int greedy()
{
    int ans = 0;
    int now, p, k = 0, Max;
    now = 1;
    while (now <= t)
    {
        if (k == n)
            return -1;
        if (a[k].start > now)
            return -1;
        Max = a[k].end;
        while (a[k].start <= now && k < n)
        {
            Max = max(Max, a[k].end);
            k++;
        }
        now = Max + 1;
        ans++;
    }
    return ans;
}
 
int main()
{
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &t) == 2)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &a[i].start, &a[i].end);
        sort(a, a+n, cmp);
        printf("%d\n", greedy());
    }
	fclose(stdin);
    return 0;

}
