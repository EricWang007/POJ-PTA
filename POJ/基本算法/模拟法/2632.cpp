// 注意：-5%4=-1
#include <cstdio>
#include <iostream>

using namespace std;

#define E 0
#define W 2
#define S 3
#define N 1

int m[105][105];  //记录几号机器人
int rx[105];
int ry[105];
int rd[105];  //机器人朝向

int main() {
  int K;
  cin >> K;
  while (K--) {
    int A, B;
    cin >> A >> B;
    for (int i = 1; i <= A; i++)
      for (int j = 1; j <= B; j++) m[i][j] = -1;
    int n, M;
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
      int t1, t2;
      char dir;
      cin >> t1 >> t2 >> dir;
      rx[i] = t1;
      ry[i] = t2;
      m[t1][t2] = i;
      switch (dir) {
        case 'E':
          rd[i] = E;
          break;
        case 'W':
          rd[i] = W;
          break;
        case 'S':
          rd[i] = S;
          break;
        case 'N':
          rd[i] = N;
          break;
        default:
          break;
      }
    }
    bool flag = true;
    for (int i = 0; i < M; i++) {
      int num, cnt;
      char op;
      cin >> num >> op >> cnt;
      if (!flag) continue;
      switch (op) {
        case 'L':
          rd[num] = (rd[num] + cnt) % 4;
          break;
        case 'R':
          rd[num] = (rd[num]-cnt%4+4)%4;
          break;
        case 'F': {
          switch (rd[num]) {
            case E:
              for (int p = rx[num] + 1; p <= A && p <= rx[num] + cnt; p++) {
                if (m[p][ry[num]] != -1) {
                  printf("Robot %d crashes into robot %d\n", num,
                         m[p][ry[num]]);
                  flag = false;
                  break;
                }
              }
              if (flag) {
                if (rx[num] + cnt > A) {
                  printf("Robot %d crashes into the wall\n", num);
                  flag = false;
                } else {
                  m[rx[num]][ry[num]] = -1;
                  rx[num] += cnt;
                  m[rx[num]][ry[num]] = num;
                }
              }
              break;

            case W:
              for (int p = rx[num] - 1; p >= 1 && p >= rx[num] - cnt; p--) {
                if (m[p][ry[num]] != -1) {
                  printf("Robot %d crashes into robot %d\n", num,
                         m[p][ry[num]]);
                  flag = false;
                  break;
                }
              }
              if (flag) {
                if (rx[num] - cnt < 1) {
                  printf("Robot %d crashes into the wall\n", num);
                  flag = false;
                } else {
                  m[rx[num]][ry[num]] = -1;
                  rx[num] -= cnt;
                  m[rx[num]][ry[num]] = num;
                }
              }
              break;

            case N:
              for (int p = ry[num] + 1; p <= B && p <= ry[num] + cnt; p++) {
                if (m[rx[num]][p] != -1) {
                  printf("Robot %d crashes into robot %d\n", num,
                         m[rx[num]][p]);
                  flag = false;
                  break;
                }
              }
              if (flag) {
                if (ry[num] + cnt > B) {
                  printf("Robot %d crashes into the wall\n", num);
                  flag = false;
                } else {
                  m[rx[num]][ry[num]] = -1;
                  ry[num] += cnt;
                  m[rx[num]][ry[num]] = num;
                }
              }
              break;

            case S:
              for (int p = ry[num] - 1; p >= 1 && p >= ry[num] - cnt; p--) {
                if (m[rx[num]][p] != -1) {
                  printf("Robot %d crashes into robot %d\n", num,
                         m[rx[num]][p]);
                  flag = false;
                  break;
                }
              }
              if (flag) {
                if (ry[num] - cnt < 1) {
                  printf("Robot %d crashes into the wall\n", num);
                  flag = false;
                } else {
                  m[rx[num]][ry[num]] = -1;
                  ry[num] -= cnt;
                  m[rx[num]][ry[num]] = num;
                }
              }
              break;

            default:
              break;
          }
        } break;
        default:
          break;
      }
    }
    if (flag) cout << "OK" << endl;
  }
  return 0;
}