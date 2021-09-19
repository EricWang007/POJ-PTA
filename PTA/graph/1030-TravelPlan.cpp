#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define inf 0x7fffffff

struct edge{
    int des;
    int len;
    int cost;
};

vector<edge> edges[501]; 
int n, m, s, d;
bool vis[501]={0};
int dis[501];
int cos[501];
int last[501];

void dfs(int v) { // djkstra
    vis[v] = true;
    last[v] = -1;
    for (int i = 0; i < n; i++) {
        dis[i] = inf;
        cos[i] = inf;
    }
    for (vector<edge>::iterator it = edges[v].begin(); it != edges[v].end(); it++) {
        dis[it->des] = it->len;
        cos[it->des] = it->cost;
        last[it->des] = v;
    }

    for (int i = 1; i < n; i++) {
        int min = inf, q;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                q = j;
            }
        }
        vis[q] = true;
        if (q == d) break;
        
        //更新
        for (vector<edge>::iterator it = edges[q].begin(); it != edges[q].end(); it++) {
            if (!vis[it->des]) {
                if (dis[it->des] > dis[q] + it->len) {
                    dis[it->des] = dis[q] + it->len;
                    cos[it->des] = cos[q] + it->cost;
                    last[it->des] = q;
                } else if (dis[it->des] == dis[q] + it->len) {
                    if (cos[it->des] > cos[q] + it->cost) {
                        cos[it->des] = cos[q] + it->cost;
                        last[it->des] = q;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < m; i++) {
        int c1, c2, d, cost;
        scanf("%d%d%d%d", &c1, &c2, &d, &cost);
        edges[c1].push_back({c2, d, cost});
        edges[c2].push_back({c1, d, cost});
    }
    if (s == d)
        printf("%d %d", s, 0);
    dfs(s);
    vector<int> ans;
    int before = d;
    while(before != s) {
        ans.push_back(before);
        before = last[before];
    }
    ans.push_back(s);
    while(ans.size()) {
        printf("%d ", ans.back());
        ans.pop_back();
    }
    printf("%d %d", dis[d], cos[d]);
    return 0;
}