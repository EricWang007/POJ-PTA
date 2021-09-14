#include<bits/stdc++.h>
using namespace std;

struct edge{
    int next;
    int val;
};

int N, K;
bool vis[3001];
int mp[3001][3001];
int nodew[3001];
map<string, int> ans;
unordered_map<string, int> si;
unordered_map<int, string> is;
int idx = 0;

int solve(string x, int &idx) {
    if (si.find(x) != si.end()) return si[x];
    si[x] = idx;
    is[idx] = x;
    idx++;
    return idx-1;
}

int visit(int node, int &total, int &head) {
    int sum = 0;
    total ++;
    if (nodew[node] > nodew[head]) head = node;
    vis[node] = true;
    for (int i = 0; i < idx; i++) {
        if (mp[node][i]>0) {
            sum += mp[node][i];
            if (!vis[i]) 
                sum += visit(i, total, head);
        }
    }
    return sum;
}

void dfs(){
    int cnt = 0;
    for (int i = 0; i < idx; i++) {
        if (!vis[i]) {
            int total = 0;
            int head = i;
            int sum = visit(i, total, head);
            if (sum/2 > K && total > 2) {
                ans[is[head]] = total;
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    for(auto it : ans) {
        cout << it.first<< " " <<it.second << endl;
    }
}

int main(){
    scanf("%d%d", &N, &K);
    fill(nodew, nodew+N, 0);
    fill(mp[0], mp[0]+N*N, 0);
    fill(vis, vis+N, false);
    for(int i = 0; i < N; i++) {
        string name1, name2;
        int val;
        cin >> name1 >> name2;
        scanf("%d", &val);
        int x = solve(name1, idx);
        int y = solve(name2, idx);
        nodew[x] += val;
        nodew[y] += val;
        mp[x][y] += val;
        mp[y][x] += val;
    }
    dfs();
    return 0;
}