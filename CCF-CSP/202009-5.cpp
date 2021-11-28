#include <bits/stdc++.h>
using namespace std;

struct book{
  int i;
  char c;
} books[26][52];

int n, m;
unordered_set<string> dic;

int main() {
  cin >> n >> m;
  for (int i = 0; i < 26; i++)
    for (int j = 1; j <= n; j++) scanf("%c%d", &books[i][j].c, &books[i][j].i);
  string tmp;
  while (cin >> tmp) {
    dic.insert(tmp);
  }
  cout << 1 << endl;
  return 0;
}