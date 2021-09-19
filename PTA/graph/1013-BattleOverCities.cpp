#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];
bool vis[1001];
int n, m;

int visit(int k) {
    vis[k] = true;
    vector<int>::iterator it = adj[k].begin();
    while (it != adj[k].end()) {
        if (vis[*it] == false) visit(*it);
        it++;
    }
}

int dfs(int k) {
    for (int i = 1; i <= n; i++) vis[i] = false;
    vis[k] = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            visit(i);
            cnt++;
        }            
    }
    return cnt;
}

int main(){
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int start, end;
        scanf("%d%d", &start, &end);
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    while (k--) {
        int del;
        scanf("%d", &del);
        printf("%d\n", dfs(del)-1);
    }
    return 0;
}