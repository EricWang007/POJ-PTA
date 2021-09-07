#include <iostream>

using namespace std;

int main() {
  int cnt;
  cin >> cnt;
  while (cnt--) {
    int n;
    int num = 0;
    int pos2 = 0, pos1 = 0;
    bool a[42];
    int b[42];
    cin >> n;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      while (num < tmp) {
        a[pos1] = 0;
        pos1++;
        num++;
      }
      a[pos1] = 1;
			pos1++;
      int res = 1, temp = 1;
      for (int j = pos1 - 2; temp > 0; j--) {
        if (a[j] == 0)
          temp--;
        else {
          temp++;
          res++;
        }
      }
      b[pos2] = res;
      pos2++;
    }
		cout << b[0];
		for(int i = 1; i < pos2; i++)
			cout<<" " << b[i];
		cout << endl;
	}
}