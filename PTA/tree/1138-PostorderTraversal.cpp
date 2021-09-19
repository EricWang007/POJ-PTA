#include<bits/stdc++.h>
using namespace std;

int pre[50005], in[50005];
int ans;

void traverse(int l1, int l2, int len) {
    int root = pre[l1];
    int idx = l2;
    while (in[idx] != root) 
        idx++;
    if (idx != l2) 
        traverse(l1+1, l2, idx-l2);
    else {
        if (idx-l2+1 == len) ans = in[idx];
        else traverse(l1+1, l2+1, len-1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    traverse(0, 0, n);
    printf("%d", ans);
    return 0;
}