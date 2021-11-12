/* CCF202104-4 校门外的树 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000 + 1;
const int AI = 100000 + 1;

int n, a[N];
long long f[N];
bool flag[AI];
vector<int> v[AI];

int main() {
    for (int i = 1; i < AI; i++)
        for (int j = 2 * i; j < AI; j += i)
            v[j].push_back(i);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        memset(flag, false, sizeof flag);
        for (int j = i - 1; j >= 1; j--) {
            int d = a[i] - a[j], cnt = 0;
            for (int k:v[d])
                if (!flag[k]) cnt++, flag[k] = true;
            flag[d] = true;
            f[i] = (f[i] + f[j] * cnt) % MOD;
        }
    }

    printf("%lld\n", f[n]);

    return 0;
}