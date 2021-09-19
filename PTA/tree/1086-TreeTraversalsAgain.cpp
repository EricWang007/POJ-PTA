#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left = NULL, *right = NULL;
    node (int v) {val = v;};
};
int before[31], in[31], post[31];

node* search(int l1, int r1, int l2, int r2) {
    if (r1 < l1) return NULL;
    node *root = new node(before[l1]);
    int idx = l2;
    while(in[idx] != before[l1]) idx++;
    root->left = search(l1+1, idx-l2+l1, l2, idx-1);
    root->right = search(idx-l2+l1+1, r1, idx+1, r2);
    return root;
};

void posttraverse(node *root) {
    if (root == NULL) return;
    posttraverse(root->left);
    posttraverse(root->right);
    printf("%d ", root->val);
}

void postT(node *root) {
    posttraverse(root->left);
    posttraverse(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> stack;
    int cnt1=0, cnt2=0;
    
    for (int i = 0; i < 2*n; i++) {
        string op;
        cin >> op;
        if (op == "Push") {
            scanf("%d", &before[cnt1++]);
            stack.push_back(before[cnt1-1]);
        }
        else {
            in[cnt2++] = stack.back();
            stack.pop_back();
        }
    }
    node* root = search(0, n-1, 0, n-1);
    postT(root);
    printf("%d", root->val);
}
