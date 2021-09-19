#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int N, M;
    vector<int> node[100];
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int k, son;
        scanf("%d%d", &k, &son);
        while(son--) {
            int tmp;
            scanf("%d", &tmp);
            node[k].push_back(tmp);
        }
    }
    if (node[1].size() == 0) {
        printf("1");
        return 0;
    }
    queue<int> que;
    que.push(1);
    while(que.size()) {
        int ans = 0;
        for (int i = que.size(); i > 0; i--) {
            int root = que.front();
            que.pop();
            if (node[root].size() == 0) ans ++;          
            else {
                for (vector<int>::iterator it = node[root].begin(); it < node[root].end(); it++)
                    que.push(*it);
            }
        }
        printf("%d", ans);
        if (que.size()) printf(" ");
    }
    return 0;
} 