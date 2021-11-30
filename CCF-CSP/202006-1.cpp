#include <bits/stdc++.h>
using namespace std;

int x[1002], y[1002];
char t[1002];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %c", &x[i], &y[i], &t[i]);
    }
    for (int j = 0; j < m; j++) {
        int t1, t2, t3;
        scanf("%d%d%d", &t1, &t2, &t3);
        bool flag = true;
        int i;
        for (i = 0; i < n; i++) {
            int ans = t1 + t2 * x[i] + t3*y[i];
            if(ans == 0) break;
            if (i == 0) flag = (ans > 0 && t[i] == 'A' || ans < 0 && t[i] == 'B');
            else if (flag != (ans > 0 && t[i] == 'A' || ans < 0 && t[i] == 'B'))
                break;
        }
        if (i != n) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}