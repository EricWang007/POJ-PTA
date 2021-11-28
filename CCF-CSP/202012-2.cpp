#include <bits/stdc++.h>

using namespace std;

struct record{
    int y;
    bool r;
};

bool cmp (const record & r1, const record &r2) {
    return r1.y < r2.y;
}

int main() {
    int m;
    scanf("%d", &m);
    vector<record> records(m);
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &records[i].y, &records[i].r);
        if (records[i].r == 1) tmp++;
    }
    sort(records.begin(), records.end(), cmp);
    int ans = tmp;
    int best = records[0].y;
    int i = 0;
    while(i < m) {
        do {
            if (records[i].r == 0) tmp++;
            else tmp--;
            i++;
        }
        while (i < m && records[i].y == records[i-1].y);
        if (tmp >= ans && i < m) {
            ans = tmp;
            best = records[i].y;
        }
    }
    printf("%d\n", best);
    return 0;
}