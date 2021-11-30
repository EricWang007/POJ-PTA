#include <bits/stdc++.h>
#define SIZE 105
using namespace std;

struct edge{
    int nxt;
    int val;
    edge(int a, int b){ nxt = a, val = b;};
};
vector<edge> edges[SIZE];
int m[SIZE][12];
int need[SIZE];
int dp[SIZE][12];
int T[SIZE];
bool cdp[12][2000]; //压缩dp
int road;
int N, M, K;

int dfs(int kind, int root, int pre) { 
// 计算以root为根的子树中，访问所有kind类节点的时间
// 同时计算最长的一条路径
    int longest = 0;
    for (auto& it : edges[root]) {
        int nxt = it.nxt, val = it.val;
        if (nxt == pre) continue; 
        int re = dfs(kind, nxt, root);
        if (need[nxt]) {
            need[root] = 1;
            road += val;
            longest = max(longest, re+val);
        }
    }
    return longest;
}

bool judge(int mid) {
    memset(T, 0, sizeof(T));
    memset(cdp, 0, sizeof(cdp));
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < K; j++) {
            if (dp[i][j] <= mid) T[i] |= 1<<j;
        }
    cdp[0][0] = true;
    for (int j = 0; j < M; j++) //j个补给站
        for (int k = 0; k<(1<<K); k++)
            for (int i = 1; i <= N; i++) //增加第i个城市
                cdp[j+1][k|T[i]] |= cdp[j][k];
    return cdp[M][(1<<K)-1];            
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < K; j++)
            cin >> m[i][j];
    for (int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(edge(b, c));
        edges[b].push_back(edge(a, c));
    }
    for (int k = 0; k < K; k++) {
        for (int r = 1; r <= N; r++) {
            memset(need, 0, sizeof(need));
            for (int i = 1; i <= N; i++)
                if (m[i][k]) need[i] = 1;
            road = 0;
            int longest = dfs(k, r, -1);
            dp[r][k] = road*2 - longest; //计算以r为根的子树中，访问所有k类节点的时间
        }
    }

    int l = 1, r = 1e9, ans = 0;
    while (l <= r) { //二分法搜索最优解。
        int mid = (l+r)/2;
        if (judge(mid)) {
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << ans << endl;

    return 0;
}