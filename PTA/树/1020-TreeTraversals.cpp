#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int post[31], in[31];
int n;
vector<vector<int>> level(30);

void traverse(int l1, int r1, int l2, int r2, int k) {
    if (r1 < l1) return;
    int root = post[r1];
    level[k].push_back(root);
    int i = l2;
    while (in[i] != root) i++;
    
    traverse(l1, l1 + i-l2-1, l2, i-1, k+1); // 左子树
    traverse(l1 + i-l2, r1-1, i+1, r2, k+1); // 右子树
}

int main(){
    scanf("%d", &n);
    if (n == 0) return 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    
    traverse(0, n-1, 0, n-1, 0);    
    
    printf("%d", level[0][0]);
    for (int i = 1; level[i].size(); i++)
        for (int j = 0; j < level[i].size(); j++)
            printf(" %d", level[i][j]);
    return 0;
}