// 货币-替代品问题 dijkstra
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

int M, N;
int dist[105];    //源点0到各点的距离
bool visit[105];  //各点是否已经访问
int lv[105];
int price[105][105];

int dijkstra() {
  FOR(i, 1, N) dist[i] = price[0][i];
  FOR(i, 1, N) {
    // 在未访问的点中寻找最短的一条，加入访问点
    int node = 0, sd = INF;
    FOR(j, 1, N)
    if (!visit[j] && dist[j] < sd) {
      sd = dist[j];
      node = j;
    }
    if (node == 0) break;
    visit[node] = true;

    // 更新dist
    FOR(j, 1, N) {
      if (!visit[j] && price[node][j] > 0)
        dist[j] = min(dist[j], dist[node] + price[node][j]);
    }
  }
  return dist[1];
}

int main() {
  FOR(i, 0, 104) dist[i] = INF;
  mst(visit);
  mst(lv);
  mst(price);

  scanf("%d%d", &M, &N);
  FOR(i, 1, N) {
    int num;
    scanf("%d%d%d", &price[0][i], &lv[i], &num);
    FOR(j, 1, num) {
      int t, v;
      scanf("%d%d", &t, &v);
      price[t][i] = v;
    }
  }

  int maxlv;
  // 枚举不同的等级限制，计算多次djkstra，每次只考虑等级小于maxlv的点
  int Min = INF;
  FOR(i, 1, N) {
    maxlv = lv[i];
    FOR(j, 1, N) {
      if (lv[j] > maxlv || maxlv - lv[j] > M)
        visit[j] = true;
      else
        visit[j] = false;
    }
    int tmp = dijkstra();
    Min = min(tmp, Min);
  }
  printf("%d\n", Min);
  return 0;
}