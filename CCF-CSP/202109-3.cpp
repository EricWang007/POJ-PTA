#include <bits/stdc++.h>
using namespace std;

int N, S, P, T;
double dertat;
int r[2003];
double Ik[1005][1003]={0};
int cnts[1003]={0};
static unsigned long Next = 1;

struct neural {
    double v, u, a, b, c, d;
} neurals[1003];

struct tuchu {
    int s, t;
    double w;
    int D;
} tuchus[1003];

vector<int> s2tuchu[2003];

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    Next = Next * 1103515245 + 12345;
    return((unsigned)(Next/65536) % 32768);
}       

int main () {
    scanf("%d%d%d%d", &N, &S, &P, &T);
    scanf("%lf", &dertat);
    int cnt = 0;
    int maxd=-1;
    while(cnt < N) {
        int rn;
        double v, u, a, b, c, d;
        scanf("%d %lf %lf %lf %lf %lf %lf", &rn, &v, &u, &a, &b, &c, &d);
        for (int i = 0; i < rn; i++)
            neurals[cnt+i] = {v, u, a, b, c, d};
        cnt += rn;
    }
    for (int i = N; i < N+P; i++)
        scanf("%d", &r[i]);
    for (int i = 0; i < S; i++) {
        scanf("%d %d %lf %d", &tuchus[i].s, &tuchus[i].t, &tuchus[i].w, &tuchus[i].D);
        s2tuchu[tuchus[i].s].push_back(i);
        maxd = max(maxd, tuchus[i].D);
    }
    
    //开始模拟
    for (int i = 1; i <= T; i++) {
        for (int l = 0; l < N; l++)
            Ik[(i+maxd)%(maxd+1)][l] = 0;

        for (int j = N; j < N+P; j++) { //脉冲源产生脉冲
            if (r[j] > myrand()) {
                for (auto& k : s2tuchu[j])
                    Ik[(i+tuchus[k].D)%(maxd+1)][tuchus[k].t] += tuchus[k].w;
            }
        }
        for (int k = 0; k < N; k++) {
            double v1 = neurals[k].v , u1 = neurals[k].u, a1 = neurals[k].a, b1 = neurals[k].b;
            neurals[k].v = v1 + dertat*(0.04*v1*v1+5.0*v1+140-u1)+Ik[i%(maxd+1)][k];
            neurals[k].u = u1 + dertat*a1*(b1*v1-u1);
            if (neurals[k].v >= 30) { //神经元产生脉冲
                neurals[k].v = neurals[k].c;
                neurals[k].u += neurals[k].d;
                cnts[k]++;   
                for (auto& m : s2tuchu[k]) 
                    Ik[(i+tuchus[m].D)%(maxd+1)][tuchus[m].t] += tuchus[m].w;
            }
        }
    }
    double Min = 100000000, Max = -100000000;
    int ansmin = 100000000, ansmax = -1;
    for (int i = 0; i < N; i++) {
        if (cnts[i] < ansmin) ansmin = cnts[i];
        if (cnts[i] > ansmax) ansmax = cnts[i];
        if (neurals[i].v < Min) Min = neurals[i].v;
        if (neurals[i].v > Max) Max = neurals[i].v;
    }
    printf("%.3lf %.3lf\n", Min, Max);
    cout << ansmin << " " << ansmax << endl;

    return 0;
}