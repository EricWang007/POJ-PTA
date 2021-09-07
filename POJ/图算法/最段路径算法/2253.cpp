// frog distance floyd/dijkstar/spfa
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

const int MAX = 1e2 + 10;
const double eps = 1e-6;
#define INF 0xfffffff  //注意不能是0x7fffffff，不然会做加法后会超。
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))

int x[205], y[205];
double m[205][205];
int n;

void floyd() { //125ms
  FOR(k, 1, n)
  FOR(i, 1, n)
  FOR(j, 1, n)
  m[i][j] = min(m[i][j], max(m[i][k], m[k][j]));
}

void dijkstra() {
	double dis[205];
	bool vis[205];
	FOR(i, 1, n) dis[i] = INF;
	dis[1] = 0;
	FOR(i, 1, n) {
		
	}
}

int main() {
  int cnt = 0;
  while (true) {
    mst(m);
    cnt++;
    scanf("%d", &n);
    if (n == 0) break;
    FOR(i, 1, n) { scanf("%d%d", &x[i], &y[i]); }
    FOR(i, 1, n)
    FOR(j, 1, n) {
      m[i][j] = m[j][i] = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
    }
    floyd();
    printf("Scenario #%d\n", cnt);
    printf("Frog Distance = %.3f\n\n", m[1][2]);
  }
  return 0;
}