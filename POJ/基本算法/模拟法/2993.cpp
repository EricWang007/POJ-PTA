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

char b[9][9];

int main() {
  string input;
  mst(b);
  FOR(cnt, 1, 4) {
    cin >> input;
    if (cnt == 1 || cnt == 3) continue;
    FOR(i, 0, input.length()-1) {
      char ch = input[i];
      if (ch == ',') continue;
      int x, y;      
      if (ch >= 'A' && ch <= 'Z') {
				y = input[i + 1] - 'a' + 1;
      	x = input[i + 2] - '0';
        if (cnt == 2)
          b[x][y] = ch;
        else
          b[x][y] = ch - 'A' + 'a';
        i += 2;
      } else {
				y = input[i] - 'a' + 1;
      	x = input[i + 1] - '0';
        if (cnt == 2)
          b[x][y] = 'P';
        else
          b[x][y] = 'p';
        i += 1;
      }
    }
  }
  string line = "+---+---+---+---+---+---+---+---+";
  ROF(i, 8, 1) {
    cout << line << endl;
    FOR(j, 1, 8) {
      char s;
      cout << "|";
      if ((i+j) % 2 == 0) s = ':';
			else s = '.';
      cout << s;
      if (b[i][j] == 0)
        cout << s;
      else
        cout << b[i][j];
      cout << s;
    }
    cout << "|" << endl;
  }
  cout << line << endl;
  return 0;
}