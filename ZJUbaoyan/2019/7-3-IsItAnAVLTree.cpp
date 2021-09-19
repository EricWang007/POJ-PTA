#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
};

vector<int> pre, in;
bool flag = false;

node* create(int l1, int l2, int len) {
    if (len <= 0) return NULL;
    node *root = new node;
    root->val = pre[l1];
    int idx = l2;
    while (in[idx] != pre[l1]) idx++;
    root->left = create(l1+1, l2, idx-l2);
    root->right = create(l1+idx-l2+1, idx+1, len-idx+l2-1);
    return root;
}

int getHeight(node *root) {
    if (flag || root == NULL) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (abs(left - right) > 1) {
        flag = true;
        return 0;
    }
    return max(left, right) + 1;
}

int main() {
    int K, N;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &N);
        pre.clear();
        pre.resize(N);
        for (int i = 0; i < N; i++)
            scanf("%d", &pre[i]);
        in = pre;
        sort(in.begin(), in.end());
        node *root = create(0, 0, N);
        flag = false;
        getHeight(root);
        if (flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}