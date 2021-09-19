#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *left, *right;
};

node* build(node *root, int v) {
    if (root == NULL) {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if(abs(v) < abs(root->val))
        root->left = build(root->left, v);
    else root->right = build(root->right, v);
    return root;
}

bool judge1(node *root) { //检查红色节点的孩子是否为黑色
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) return false;
        if (root->right != NULL && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}

int judge2(node *root) { //检查每个节点左右子树中黑色节点的个数是否相等
    if (root == NULL) return 0;
    int l = judge2(root->left);
    int r = judge2(root->right);
    if (l == -1 || r == -1 || l != r) return -1;
    return root->val > 0 ? l+1 : l;
}

int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        int tmp;
        bool flag = false;
        node *root = NULL;
        for (int j = 0; j < n; j++) { //建树
            scanf("%d", &tmp);
            if (j == 0 && tmp < 0) flag = true;
            root = build(root, tmp);
        }
        if (flag || !judge1(root) || judge2(root) == -1)
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}