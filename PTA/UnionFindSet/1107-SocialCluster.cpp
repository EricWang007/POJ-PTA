#include<bits/stdc++.h>
using namespace std;

int h[1001], father[1001];
int siz[1001];

int find(int x) { //非递归压缩路径
    int node = x;
    while (father[node] != node) node = father[node];
    while (x != node) {
        int temp = father[x];
        father[x] = node;
        x = temp;
    }
    return node;
}

void merge(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if (r1 != r2) {
        if (siz[r1] > siz[r2]) {
            father[r2] = r1;
            siz[r1] += siz[r2];
        } else {
            father[r1] = r2;
            siz[r2] += siz[r1];
        }        
    }
}

int main() {
    int n;
    scanf("%d", &n);
    fill(h, h+1005, -1);
    fill(siz, siz+1005, 1);
    for (int i = 0; i < n; i++) {
        father[i] = i;
        int k;
        scanf("%d:", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            if (h[x] == -1) h[x] = i;
            else merge(i, h[x]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (father[i] == i)
            ans.push_back(siz[i]);
    sort(ans.begin(), ans.end(), greater<int>());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i+1==ans.size() ? '\n' : ' ');
    return 0;
}