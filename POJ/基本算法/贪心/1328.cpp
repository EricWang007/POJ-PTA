#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

class A {
 public:
  double x, y, left, right;
  bool operator<(const A &t) const {
    if (right != t.right)
      return right < t.right;
    else
      return left < t.left;
  };
} a[1001];

int main() {
  int cnt = 0;
  while (true) {
    cnt++;
    int n;
    double d;
    bool wrong = false;
    scanf("%d%lf", &n, &d);
    getchar();
    if (n == 0 && d == 0)
      break;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &a[i].x, &a[i].y);
      getchar();
      if (a[i].y > d)
        wrong = true;
      else {
        double tmp = sqrt(pow(d, 2) - pow(a[i].y, 2));
        a[i].left = a[i].x - tmp;
        a[i].right = a[i].x + tmp;
      }
    }
    if (wrong)
      printf("Case %d: -1\n", cnt);
    else {
      sort(a, a + n);
      double temp = a[0].right;
      int num = 1;
      for (int i = 1; i < n; i++) {
        if (a[i].left > temp) {
          num++;
          temp = a[i].right;
        }
      }
      printf("Case %d: %d\n", cnt, num);
    }
    getchar();
  }
  return 0;
}