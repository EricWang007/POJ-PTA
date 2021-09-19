#include<bits/stdc++.h>
using namespace std;

struct student {
    int id=0;
    int score=0;
}students[10005];

struct school {
    int id=0;
    int cnt=0;
    int score=0;
};

vector<school> ans;

int N;
int father[10005];

int find(int id) {
    int node = id;
    while (father[node] != node) node = father[node];
    while (id != node) {
        int tmp = father[id];
        father[id] = node;
        id = tmp;
    }
    return node;
}

void merge(int id1, int id2) {
    int x = find(id1);
    int y = find(id2);
    if (x != y) {
        father[x] = y;
    }
}

bool cmp(const school &s1, const school &s2) {
    if (s1.score == s2.score)
        return s1.cnt == s2.cnt ? s1.id < s2.id : s1.cnt < s2.cnt;
    return s1.score > s2.score;
}

int main() {
    scanf("%d", &N);
    bool exist[10005];
    fill(exist, exist+10005, false);
    for (int i = 0; i < 10005; i++) father[i] = i;
    for (int i = 0; i < N; i++) {
        int id, k;
        scanf("%d%d", &id, &k);
        students[id].id = id;
        exist[id] = true;
        while (k--) {
            int tmp_id;
            scanf("%d", &tmp_id);
            students[tmp_id].id = tmp_id;
            exist[tmp_id] = true;
            merge(id, tmp_id);
        }
        scanf("%d", &students[id].score);
    }
    int sum = 0;
    int cnt[10005]={0}, smallid[10005], totalscore[10005]={0};
    fill(smallid, smallid+10005, 100000);
    for (int i = 0; i < 10005; i++) {
        int root = find(i);
        if (exist[root]) {
            cnt[root]++;
            smallid[root] = min(smallid[root], students[i].id);
            totalscore[root] += students[i].score;
        }
    }
    for (int i = 0; i < 10005; i++)
        if (cnt[i] > 0) {
            sum++;
            ans.push_back({smallid[i], cnt[i], totalscore[i]});
        }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", sum);
    for (auto it : ans) {
        printf("%04d %d %d\n", it.id, it.cnt, it.score);
    }
    return 0;
}