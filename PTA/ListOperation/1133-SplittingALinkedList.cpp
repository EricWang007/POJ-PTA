#include<bits/stdc++.h>
using namespace std;

struct node {
    int id, val, next;
};

int N, K, start;

int main() {
    scanf("%d%d%d", &start, &N, &K);
    node a[100005];
    for (int i = 0; i < N; i++) {
        node tmp;
        scanf("%d%d%d", &tmp.id, &tmp.val, &tmp.next);
        a[tmp.id] = tmp;
    }
    vector<node> v, ans;
    while(start != -1) {
        v.push_back(a[start]);
        start = a[start].next;
    }
    for (int i = 0; i < v.size(); i++) 
        if (v[i].val < 0) 
            ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++) 
        if (0 <= v[i].val && v[i].val <= K) 
            ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++) 
        if (v[i].val > K) 
            ans.push_back(v[i]);
    for (int i = 0; i < ans.size()-1; i++) 
        printf("%05d %d %05d\n", ans[i].id, ans[i].val, ans[i+1].id);
    printf("%05d %d -1", ans[ans.size()-1].id, ans[ans.size()-1].val);
    return 0;
}