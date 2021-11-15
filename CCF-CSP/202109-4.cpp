/*202109-4：收集卡牌 压缩dp*/
#include <bits/stdc++.h>

double dp[1<<16][100];
int cnt[1<<16]={0};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    double p[20];
    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);
    dp[0][0] = 1;
    for (int i = 1; i <= (1<<n); i++) {
        int x = i;
        while (x) {
            x &= x-1;
            cnt[i]++;
        }
    }
    double ans = 0;
    for (int i = 0; i < (1<<n); i++) 
        for (int j = 0; j < 100; j++) {
            if (cnt[i] + (j-cnt[i])/k == n) { //可以换了
                ans += j * dp[i][j];
                continue;
            }
            for (int k = 1; k <= n; k++) { //新抽一张牌 
                if (i & (1 << (k-1))) dp[i][j+1] += dp[i][j]*p[k]; // 抽到过
                else dp[i+(1<<(k-1))][j+1] += dp[i][j]*p[k];
            }
        }
    printf("%lf", ans);

    return 0;
}