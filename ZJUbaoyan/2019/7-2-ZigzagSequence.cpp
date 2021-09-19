#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ans[i]);
    }
    sort(ans.begin(), ans.end());
    int line = n/m;
    int res = n%m;
    bool flag = true;
    for (int i = 1; i <= line; i++, flag = !flag) {
        if (flag) {
            for (int j = 0; j < m; j++) 
                printf("%d%c", ans[(i-1)*m+j], j==m-1 ?'\n':' ');
        } else {
            for (int j = 1; j <= m; j++)
                printf("%d%c", ans[i*m-j], j==m?'\n':' ');
        }
    }
    if (res) {
        if (flag) 
            for(int i = line*m; i < n; i++)
                printf("%d%c", ans[i], i==n-1?'\n':' ');
        else for(int i = n-1; i >= line*m; i--)
            printf("%d%c", ans[i], i==(line-1)*m?'\n':' ');
    }
    return 0;
}