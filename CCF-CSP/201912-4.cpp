#include<bits/stdc++.h>
using namespace std;

struct state {
    int t;
    int start;
    vector<int> tlink;
    state(int tt, int ss, vector<int> ll) {t = tt, start = ss, tlink = ll;};
};

vector<int> edge[505];
vector<int> link[505];
deque<state> Q;
int m, n, t, k;

void change(int b) {
//    cout << "time " << b << endl;
//    for (auto &it : Q)
//        cout << " " <<it.t << " " << it.start << " " << it.tlink.size() << endl;
    while (!Q.empty() && Q.front().t + t <= b) {
        state tmp = Q.front();
        int start = tmp.start;
        vector<int> tlink = tmp.tlink;
        Q.pop_front();
        for (auto &it : edge[start]) {
            if (link[it].size() < tlink.size() || (link[it].size() == tlink.size() && link[it].back() > tlink.back())) {
                link[it] = tlink;
                Q.push_back(state(tmp.t+t, it, link[it]));
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) link[i].push_back(0);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    scanf("%d%d", &t, &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        change(b);

        int ch = getchar();
        if (ch == '\n') {
            printf("%d", link[a].size());
            for (auto &it :link[a])
                printf(" %d", it);
            printf("\n");
        } else {
            int c;
            scanf("%d", &c);
            link[a].push_back(c);
            Q.push_back(state(b, a, link[a]));
        }
    }
    return 0;
}
