/* 箱根山岳险天下， 10分 */
#include<bits/stdc++.h>
using namespace std;

vector<int> ranks[300001];

long long stus[300001];
// ofstream outf("out.txt");

int main() {
    int m, T;
    int p;
    int cnt = 0;
    cin >> m >> p >> T;
    int A = 0;
    for (int i = 0; i < m; i++) {
        int event;
        if (i > 0) ranks[i] = ranks[i-1];
        scanf("%d", &event);
        if (event == 1) {
            long long strength;
            scanf("%lld", &strength); 
            strength ^= A;
            if (strength == 0)
                ranks[i].erase(ranks[i].end()-1);
            else {
                ranks[i].push_back(cnt);                
                stus[cnt++] = strength;
            }
        } else if (event == 2) {
            int s, l, r;
            long long y;
            scanf("%d %d %d %lld", &s, &l, &r, &y);
            y ^= A;
            int cnt = 0;
            for (auto &it :ranks[s-1]) {
                cnt++;
                if (cnt < l) continue;
                if (cnt > r) break;
                stus[it] = (stus[it] * y) % p;
            }
        } else if (event == 3) {
            int s, l, r;
            int cnt = 0;
            long long sum = 0;
            scanf("%d %d %d", &s, &l, &r);
            for (auto &it :ranks[s-1]) {
                cnt++;
                if (cnt < l) continue;
                if (cnt > r) break;
                sum = (sum + stus[it]) % p;
            }
            printf("%d\n", sum);
            // outf << sum << endl;
            A = sum;
        }
    }
    return 0;
}