// 货币兑换问题，bellman-ford
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
#define INF 0x7fffffff
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define mstn(a, n) memset(a, n, sizeof(a))

int N, M, S;
double V;
double m[105];
int edge_n = 0;
struct edge {
  int a;
  int b;
  double r;
  double c;
} edges[202];

bool bellman() {
  bool flag;
  FOR(i, 1, N) {  //寻找正权环
    flag = false;
    FOR(j, 1, edge_n)
    if (m[edges[j].b] < (m[edges[j].a] - edges[j].c) * edges[j].r) {
      m[edges[j].b] = (m[edges[j].a] - edges[j].c) * edges[j].r;
      flag = true;
    }
    if (!flag) return false;
  }
  return true;
}

int main() {
  scanf("%d %d %d %lf", &N, &M, &S, &V);
  // cin >> N >> M >> S >> V;
  mst(m);

  FOR(i, 1, M) {
    int a, b;
    double c, d, e, f;
    scanf("%d %d %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
    // cin >> a >> b >> c >> d >> e >> f;
    edges[++edge_n] = (struct edge){a, b, c, d};
    edges[++edge_n] = (struct edge){b, a, e, f};
  }
  m[S] = V;
  if (bellman())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}