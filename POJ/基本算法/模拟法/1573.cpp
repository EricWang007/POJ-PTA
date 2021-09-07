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

char m[12][12];
int s[12][12];

int main() {
  int N, M, start;
  while (true) {
    cin >> N >> M >> start;
    if (N == 0 && M == 0 && start == 0) break;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) cin >> m[i][j];
    mstn(s, -1);
    int ix = 1, iy = start;
    int step = 0;
    while (true) {
      if (s[ix][iy] == -1) {
        s[ix][iy] = step;
        step++;
      } else {
        printf("%d step(s) before a loop of %d step(s)\n", s[ix][iy],
               step - s[ix][iy]);
        break;
      }
      char ch = m[ix][iy];
      if (ch == 'N')
        ix--;
      else if (ch == 'S')
        ix++;
      else if (ch == 'E')
        iy++;
      else if (ch == 'W')
        iy--;
      if (ix < 1 || ix > N || iy < 1 || iy > M) {
        printf("%d step(s) to exit\n", step);
        break;
      }
    }
  }
  return 0;
}
