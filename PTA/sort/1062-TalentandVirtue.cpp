#include <bits/stdc++.h>
using namespace std;

int N, L, H;

struct person {
    int id, vir, tal;
};

vector<person> plist[4];

bool cmp(const person & p1, const person & p2) {
    int total1 = p1.tal + p1.vir;
    int total2 = p2.tal + p2.vir;
    if (total1 == total2)
        return p1.vir == p2.vir ? p1.id < p2.id : p1.vir > p2.vir;
    return total1 > total2;
}

int main() {
    scanf("%d%d%d", &N, &L, &H);
    int cnt = 0;
    while (N--) {
        person tmp;
        scanf("%d%d%d", &tmp.id, &tmp.vir, &tmp.tal);
        if (tmp.tal < L || tmp.vir < L) continue;
        cnt++;
        if (tmp.vir >= H && tmp.tal >= H)
            plist[0].push_back(tmp);
        else if (tmp.tal < H && tmp.vir >= H)
            plist[1].push_back(tmp);
        else if (tmp.tal < H && tmp.vir < H && tmp.vir >= tmp.tal)
            plist[2].push_back(tmp);
        else plist[3].push_back(tmp);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < 4; i++) {
        sort(plist[i].begin(), plist[i].end(), cmp);
        for (auto it : plist[i])
            printf("%08d %d %d\n", it.id, it.vir, it.tal);
    }
    return 0;
}