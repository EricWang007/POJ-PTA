#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

#define MAX 10001

vector<int>graph[MAX];
int n, max_dep;
int vis[MAX] = {0};
set<int> ans;

void dfs(int v, int dep) {
    vis[v] = true;
    int size = graph[v].size();
    if (dep > max_dep) {
        max_dep = dep;
        ans.clear();
        ans.insert(v);
    } else if (dep == max_dep)
        ans.insert(v); 
    for (int i = 0; i < size; i++) {
        int next = graph[v][i];
        if (!vis[next]) {
            dfs(next, dep+1);
        }
    }
}


int connect() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, 0);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int cnt = connect();
    if (cnt > 1) printf("Error: %d components", cnt);
    else {
        int root = *(ans.begin());
        for (int i = 0; i <= n; i++) vis[i] = false;
        set<int> arr = ans;
        dfs(root, 0);
        ans.insert(arr.begin(), arr.end());
        for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}