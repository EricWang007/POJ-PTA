// 虫洞问题，bellman-ford
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
#define INF 0xfffffff //注意不能是0x7fffffff，不然会做加法后会超。
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define mstn(a, n) memset(a, n, sizeof(a))

int F, N, M, W;
int all;

int m[505];

struct edge {
  int a;
  int b;
  int val;
} edges[6000];

bool bellman() {
	for (int i = 0; i <505; i++) m[i] = INF;
  m[1] = 0;
  FOR(i, 1, N) {  //寻找正权环
    FOR(j, 1, all)
    if (m[edges[j].b] > m[edges[j].a] + edges[j].val) {
      m[edges[j].b] = m[edges[j].a] + edges[j].val;
    }
  }
	FOR(j, 1, all)
    if (m[edges[j].b] > m[edges[j].a] + edges[j].val) {
      return true;
    }
  return false;
}

int main() {
  scanf("%d", &F);
  while (F--) {
    scanf("%d%d%d", &N, &M, &W);
		all = 0;
    FOR(i, 1, M) {
      int a, b, v;
      scanf("%d%d%d", &a, &b, &v);
      edges[++all] = (struct edge){a, b, v};
      edges[++all] = (struct edge){b, a, v};
    }
    FOR(i, 1, W) {
      int a, b, v;
      scanf("%d%d%d", &a, &b, &v);
      edges[++all] = (struct edge){a, b, -v};
    }
    if (bellman())
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}