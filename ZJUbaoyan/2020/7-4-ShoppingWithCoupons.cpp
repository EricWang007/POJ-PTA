#include<bits/stdc++.h>
using namespace std;

int N, D;
vector<int> price, coupon;
map<int, int> once;

int main() {
    scanf("%d%d", &N, &D);
    price.resize(N);
    coupon.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &price[i]);
    for (int i = 0; i < N; i++) scanf("%d", &coupon[i]);
    sort(price.begin(), price.end(), less<int>());
    sort(coupon.begin(), coupon.end(), greater<int>());
    int minori = price[0];
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp = price[i] - coupon[j];
            if (tmp > minori) break;
            if (once.count(tmp) != 1) once[tmp] = 1;
            else once[tmp]++;
        }
    }
    int cnt = 0;
    auto it = once.begin();
    bool flag = true;
    while (flag) {
        if (it != once.end()) {
            while (D - it->first >= 0 && it->second) {
                D -= it->first;
                it->second--;
                cnt++;
            }
            if (it->second) flag = false;
            it++;
        } else {
            while (D - minori >= 0) {
                D -= minori;
                cnt++;
            }
            flag = false;
        }
    }
    printf("%d %d", cnt, D);
    return 0;
}