#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
set<int, less<int>> que;
unordered_map<int, vector<int>> hashmap;
int n;

int count() {
    int cnt = 0;
    for (auto& i : hashmap[0]) {
        if (i < n-1 && arr[i+1] != 0) cnt++;
    }
    return cnt;
}

int change() {
    int head = *que.begin();
    que.erase(que.begin());
    int cnt = 0;
    for (auto& i: hashmap[head]) {
        arr[i] = 0;
        hashmap[0].push_back(i);
        if ((i==0 || arr[i-1] == 0) && (i == n-1 || arr[i+1] == 0)) cnt--;
        else if ((i!=0 && arr[i-1] != 0) && (i != n-1 && arr[i+1] != 0)) cnt++;
    }
    hashmap.erase(head);
    return cnt;
}

int main() {
    scanf("%d", &n);

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        que.insert(arr[i]);
        hashmap[arr[i]].push_back(i);
    }
    if (*que.begin() == 0) que.erase(que.begin());
    hashmap[0].push_back(-1);
    
    int cnt = count();
    int ans = cnt;
    while (cnt) {
        cnt += change();
        if (cnt > ans) ans = cnt;
    }
    printf("%d\n", ans);

    return 0;
}