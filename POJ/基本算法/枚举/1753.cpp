#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
bool pos[5][5];
bool tmp[5][5];

bool check() {
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      if (tmp[i][j] != tmp[1][1]) return false;
    }
  }
  return true;
}

void change(int num) {
  int i = num / 4 + 1;
  int j = num % 4 + 1;
  tmp[i][j] ^= 1;
  if (i != 4) tmp[i + 1][j] ^= 1;
  if (j != 4) tmp[i][j + 1] ^= 1;
  if (i != 1) tmp[i - 1][j] ^= 1;
  if (j != 1) tmp[i][j - 1] ^= 1;
}

int main() {
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      if ('b' == getchar())
        pos[i][j] = true;
      else
        pos[i][j] = false;
			tmp[i][j] = pos[i][j];
    }
    getchar();
  }
  if (check()) {
    printf("0\n");
    return 0;
  }
  int Min = 17;
  for (int i = 1; i < pow(2, 16); i++) {
    for (int i = 1; i < 5; i++) {
      for (int j = 1; j < 5; j++) {
        tmp[i][j] = pos[i][j];
      }
    }
    int cnt = 0;
    for (int j = 0; j < 16; j++) {
      if (i & (1 << j)) {
        change(j);
        cnt++;
        if (cnt > Min) break;
      }
    }
    if (check()) {
      Min = min(Min,cnt);
    }
  }
  if (17 == Min)
    printf("Impossible\n");
  else
    printf("%d\n", Min);
  return 0;
}