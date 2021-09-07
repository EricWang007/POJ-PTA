#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int pos[5][5];
int tmp[5][5];
int ans[20][2];
int cnt = 0;

void change(int a, int b) {
  for (int i = 1; i < 5; i++) {
    tmp[a][i]++;
    tmp[i][b]++;
  }
  tmp[a][b]--;
}

int main() {
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      if ('+' == getchar())
        pos[i][j] = true;
      else
        pos[i][j] = false;
      tmp[i][j] = 0;
    }
    getchar();
  }
  for (int i = 1; i < 5; i++)
    for (int j = 1; j < 5; j++)
      if (pos[i][j]) change(i, j);
  for (int i = 1; i < 5; i++)
    for (int j = 1; j < 5; j++)
      if (tmp[i][j] % 2 == 1) {
        ans[cnt][0] = i;
        ans[cnt][1] = j;
        cnt++;
      }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}
