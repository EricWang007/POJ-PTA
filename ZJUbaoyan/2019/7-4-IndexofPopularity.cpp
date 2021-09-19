#include<bits/stdc++.h>
using namespace std;

struct degree {
    int id, cnt;
};

int N, M;
vector<vector<int>> edge;

bool cmp (const degree &e1, const degree &e2) {
    return e1.cnt == e2.cnt ? e1.id < e2.id : e1.cnt > e2.cnt;
}

int main() {
    scanf("%d%d", &N, &M);
    edge.resize(M);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    while (true) {
        int k;
        scanf("%d", &k);
        vector<degree> degrees(k);
        if (k == 0) break;
        for (int i = 0; i < k; i++) 
            scanf("%d", &degrees[i].id);
        map<int, int> cnt;
        for (int i = 0; i < k; i++) {
            vector<int> tmp = edge[degrees[i].id];
            for (auto it : tmp) 
                cnt[it]++;
        }
        for (auto &it : degrees)
            it.cnt = cnt[it.id];
        sort(degrees.begin(), degrees.end(), cmp);
        auto it = degrees.begin();
        printf("%d %d %d\n", it->id, (it+1)->id, (it+2)->id);
    }
    return 0;
}