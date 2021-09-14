#include<bits/stdc++.h>
using namespace std;

int n;
int father[10005];
int h[10005];

int find(int b) {
    int node = b;
    while (node != father[node]) node = father[node];
    while (b != node) {
        int tmp = father[b];
        father[b] = node;
        b = tmp;
    }
    return node;
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        father[a] = b;
    }
}

int main() {
    for (int i = 0; i < 10004; i++)
        father[i] = i;
    scanf("%d", &n);
    fill(h, h+10004, -1);
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        int k, f;
        scanf("%d%d", &k, &f);
        Max = max(Max, f);
        k--;
        while (k--) {
            int bird;
            scanf("%d", &bird);
            Max = max(Max, bird);
            merge(bird, f);
        }
    }
    unordered_map<int, int> mymap;
    for (int i = 1; i <= Max; i++) {
        int root = find(i);
        if(mymap.count(root) == 0) mymap[root] = 1;
        else mymap[root]++;
    }
    printf("%d %d\n", mymap.size(), Max);
    int p;
    scanf("%d", &p);
    while (p--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (find(a) == find(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}