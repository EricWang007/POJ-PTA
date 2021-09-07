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

#define K 0
#define Q 1
#define R 2
#define B 3
#define N 4
#define P 5

char type1[] = {'k', 'q', 'r', 'b', 'n', 'p'};
set<char> t1(type1, type1 + 6);
char type2[] = {'K', 'Q', 'R', 'B', 'N', 'P'};
set<char> t2(type2, type2 + 6);

char b[9][9];
struct piece {
  char c;
  int i;
};

vector<piece> white[6];
vector<piece> black[6];

int main() {
  FOR(i, 1, 17) {
    string s;
    cin >> s;
    if (i % 2 == 0) FOR(j, 0, 7) b[9 - i / 2][j + 1] = s[2 + 4 * j];
  }
  int w_sum = 0, b_sum = 0;
  ROF(i, 8, 1)
  FOR(j, 1, 8)
  if (t1.find(b[i][j]) != t1.end()) {
    w_sum++;
    piece tmp;
    tmp.c = 'a' + j - 1;
    tmp.i = i;
    if (b[i][j] == 'k')
      black[K].push_back(tmp);
    else if (b[i][j] == 'q')
      black[Q].push_back(tmp);
    else if (b[i][j] == 'r')
      black[R].push_back(tmp);
    else if (b[i][j] == 'b')
      black[B].push_back(tmp);
    else if (b[i][j] == 'n')
      black[N].push_back(tmp);
    else if (b[i][j] == 'p')
      black[P].push_back(tmp);
  }
  FOR(i, 1, 8)
  FOR(j, 1, 8)
  if (t2.find(b[i][j]) != t2.end()) {
    b_sum++;
    piece tmp;
    tmp.c = 'a' + j - 1;
    tmp.i = i;
    if (b[i][j] == 'K')
      white[K].push_back(tmp);
    else if (b[i][j] == 'Q')
      white[Q].push_back(tmp);
    else if (b[i][j] == 'R')
      white[R].push_back(tmp);
    else if (b[i][j] == 'B')
      white[B].push_back(tmp);
    else if (b[i][j] == 'N')
      white[N].push_back(tmp);
    else if (b[i][j] == 'P')
      white[P].push_back(tmp);
  }
  cout << "White: ";
  int tmp = 0;
  FOR(i, K, K + 5)
  for (vector<piece>::iterator it = white[i].begin(); it != white[i].end();
       it++) {
    tmp++;
    if (i != P) cout << type2[i];
    cout << it->c << it->i;
    if (tmp != w_sum) cout << ",";
  }
  cout << endl;
  cout << "Black: ";
  tmp = 0;
  FOR(i, K, K + 5)
  for (vector<piece>::iterator it = black[i].begin(); it != black[i].end();
       it++) {
    tmp++;
    if (i != P) cout << type2[i];
    cout << it->c << it->i;
    if (tmp != b_sum) cout << ",";
  }
  cout << endl;
  return 0;
}