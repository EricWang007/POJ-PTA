#include <bits/stdc++.h>

using namespace std;

const int N = 600 + 1;
int a[N][N], psum[N][N];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(psum, 0, sizeof psum);

    int n, l, r, t;
    cin >> n >> l >> r >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            psum[i][j] = psum[i][j - 1] + psum[i - 1][j] - psum[i-1][j-1] + a[i][j];
        }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int l2 = max(j - r, 1), r2 = min(j + r, n);
            int u = max(i - r, 1), d = min(i + r, n);
            int t2 = psum[d][r2] - psum[d][l2 - 1] - psum[u - 1][r2] + psum[u - 1][l2 - 1];
            if (t2 <= (d - u + 1) * (r2 - l2 + 1) * t) cnt++;
        }

    cout << cnt << endl;

    return 0;
}