//与1003对比，本题局部最优！=全局最优，故不可以用djkstra
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int des;
    int num;
    edge(int d, int n) {des = d; num = n;};
};

int C, N, S, M;
int bikes[505];
vector<edge> edges[505];
vector<int> route, ans;
bool vis[505] = {0};
int shortest = 0x7fffffff, least = 0x7fffffff, ans_back = 0;

void dfs(int v, int length, int take, int back) {
    vis[v] = true;
    route.push_back(v);
    if (v == S) {        
        if (length < shortest) {
            shortest = length;
            ans = route;
            least = take;
            ans_back = back;
        } else if (length == shortest) {
            if (take < least) {
                least = take;
                ans = route;
                ans_back = back;
            } else if (take == least && back < ans_back) {
                ans_back = back;
                ans = route;
            }
        }        
        return;
    }
    for (int i = 0; i < edges[v].size(); i++) {
        int des = edges[v][i].des;
        int len = edges[v][i].num;
        if (!vis[des] && length + len <= shortest) {
            int need = C/2-bikes[des];
            int new_take = take, new_back = back;
            if (need > 0) {
                new_back = max(0, back - need);
                new_take += max(0, need - back);
            } else {
                new_take = take;
                new_back -= need;
            }
            dfs(des, length + len, new_take, new_back);
            vis[des] = false;
            route.pop_back();
        }
    }
}

int main(){
    scanf("%d%d%d%d", &C, &N, &S, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &bikes[i]);
    for (int i = 1; i <= M; i++) {
        int start, end, num;
        scanf("%d%d%d", &start, &end, &num);
        edges[start].push_back(edge(end, num));
        edges[end].push_back(edge(start, num));
    }
    dfs(0, 0, 0, 0);
    printf("%d", least);
    printf(" 0");
    for (int i = 1; i < ans.size(); i++)
        printf("->%d", ans[i]);
    printf(" %d", ans_back);
    return 0;
}
