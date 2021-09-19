#include<bits/stdc++.h>
using namespace std;

int n, a[20];
map<int, int, greater<int>> ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ans[0] = 1;
    for(int i = 0; i < n; i++) {
        map<int, int, greater<int>> tmp, ans1;
        tmp[0] = -a[i], tmp[1] = 1;
        for (auto item1 : ans)
            for (auto item2 : tmp) {
                ans1[item1.first + item2.first] += item1.second * item2.second;
            }
        ans = ans1;
    }
    auto it = ans.begin();
    it++;
    for (; it != ans.end(); it++) {
        printf("%d%c", it->second, it->first == 0 ? '\n' : ' ');
    }
    return 0;
}