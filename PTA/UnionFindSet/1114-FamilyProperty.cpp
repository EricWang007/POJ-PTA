#include <bits/stdc++.h>
using namespace std;

int N;
int father[10005];

struct node{
    int id;
    int cnt = 0;
    double estate = 0;
    double area = 0;
}nodes[10005];

int find(int v) {
    int a = v;
    while (father[a] != a) a = father[a];
    while (v != a) {
        int tmp = father[v];
        father[v] = a;
        v = tmp;
    }
    return v;
}

void Union(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        if (a < b) father[b] = a;
        else father[a] = b;
    }
}

bool cmp (const node &n1, const node &n2) {
    double a1 = n1.area / n1.cnt, a2 = n2.area / n2.cnt;
	return a1 != a2 ? a1 > a2 :n1.id < n2.id;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 10000; i++)
        father[i] = i;
    for (int i = 0; i < N; i++) {
        int id, fa, mo, sonn, son;
        scanf("%d%d%d%d", &id, &fa, &mo, &sonn);
        nodes[id].id = id;
        if (fa != -1) Union(id, fa);
        if (mo != -1) Union(id, mo);
        while (sonn --) {
            scanf("%d", &son);
            Union(id, son);
        }
        scanf("%lf%lf", &nodes[id].estate, &nodes[id].area);
    }
    vector<node> root(10000); 
    for (int i = 0; i < 10000; i++) {
        int r = find(i);
        root[r].id = r;
        root[r].cnt++;
        root[r].area += nodes[i].area;
        root[r].estate += nodes[i].estate;
    }
    vector<node> res;
    for (int i = 0; i < 10000; i++) {
        if (root[i].area != 0) res.push_back(root[i]);
    }
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    for (auto it : res) 
        printf("%04d %d %.3lf %.3lf\n", it.id, it.cnt, it.estate/it.cnt, it.area/it.cnt);
    return 0;
}