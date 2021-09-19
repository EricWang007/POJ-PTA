#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;

int G[MAXN][MAXN];
int vset[MAXN], a[MAXN];

int main() {
    int Nv, Ne, M;
    scanf("%d%d", &Nv, &Ne);
    fill(G[0], G[0]+MAXN*MAXN, 0);
    for (int i = 0; i < Ne; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1]=true;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int k, v;
        scanf("%d", &k);
        fill(a, a+MAXN, 0);
        fill(vset, vset+MAXN, 0);
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            vset[j] = v;
            a[v] = 1;
        }
        // 检查是否clique
        bool flag = false;
        for (int j = 0; j < k-1 && !flag; j++) {
            for (int l = j+1; l < k; l++) {
                if (G[vset[j]][vset[l]] == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            printf("Not a Clique\n");
            continue;
        }
        // 检查是否Maximal
        int cnt = 0;
        for (int j = 1; j <= Nv; j++) {
            for (int l = 0 ; l < k; l++) {
                if (G[j][vset[l]] == 1) cnt++;
            }
            if (cnt == k) break;
            else cnt = 0; 
        }
        if (cnt == k) printf("Not Maximal\n");
        else printf("Yes\n");
    }
    return 0;
}