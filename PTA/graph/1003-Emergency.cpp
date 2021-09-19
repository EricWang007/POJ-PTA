//与1018对比，本题局部最优->全局最优，故可以用djkstra

#include <iostream>
#include <algorithm>

using namespace std;
#define CITYS 502
#define INF 0x7fffffff
int N, M, C1, C2;
int resc[CITYS], road[CITYS][CITYS]={0}, dis[CITYS], num[CITYS]={0}, max_resc[CITYS]={0};
bool vis[CITYS]={0};

void djkstra() {
    //初始化
    vis[C1] = true;
    for (int i = 0; i < N; i++) {
        if (road[C1][i] > 0) {
            dis[i] = road[C1][i];
            num[i] = 1;
            max_resc[i] = resc[C1] + resc[i];
        } else dis[i] = INF;
    }
    dis[C1] = 0;
    max_resc[C1] = resc[C1];
    
    for (int i = 1; i < N; i++) { //执行N-1次，每次找出一个点的最段路径
        //选最小的一个
        int Min = INF;
        int q = 0;
        for (int j = 0; j < N; j++) { 
            if (!vis[j] && dis[j] < Min) {
                Min = dis[j];
                q = j;
            }
        }
        vis[q] = true;
        if (q == C2) {
            printf("%d %d", num[q], max_resc[q]);
            return ;
        }
        // 更新
        for (int j = 0; j < N; j++) { 
            if (!vis[j] && road[q][j] != 0) {
                int d = dis[q] + road[q][j];
                if (d < dis[j]) {
                    dis[j] = d;
                    num[j] = num[q];
                    max_resc[j] = max_resc[q] + resc[j];
                } else if (d == dis[j]) {
                    num[j] += num[q];
                    max_resc[j] = max(max_resc[j], max_resc[q]+resc[j]);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; i++)
        scanf("%d", &resc[i]);
    for (int i = 0; i < M; i++) {
        int begin, end, tmp;
        scanf("%d%d%d", &begin, &end, &tmp); // 注意道路为双向
        road[begin][end] = tmp;
        road[end][begin] = tmp; 
    }
    if (C1 == C2) printf("%d %d", 1, resc[C1]);
    else djkstra();
    return 0;
}