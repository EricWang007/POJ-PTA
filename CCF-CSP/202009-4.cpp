#include <bits/stdc++.h>
using namespace std;

int n, m;
double r;
double center[105];
double des[2005][105];
double finaldis[2005][2005]={0};
double eachdis[2005];

double dis(double p1[105], double p2[105]) {
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += (p1[i]-p2[i])*(p1[i]-p2[i]);
    return sqrt(ans);
}

double cal (int i, int j) {
    if (finaldis[i][j]) return finaldis[i][j];
    double ans = 0;
    double dis1 = eachdis[i], dis2 = eachdis[j], dis3 = dis(des[i], des[j]);
    // 判断两点是否直线可达
    double p = (dis1+dis2+dis3)/2;
    double S = sqrt(p*(p-dis1)*(p-dis2)*(p-dis3));
    double h = 2*S/dis3;
    if (h >= r || dis3*dis3+dis1*dis1<=dis2*dis2 ||dis3*dis3+dis2*dis2<=dis1*dis1)
        ans = dis3;
    else {
        /**曲线路程 = 黑洞表面曲线部分 + x点到切点的距离 + y点到切点的距离**/
        double part1 = acos((dis1*dis1+dis2*dis2-dis3*dis3)/(2*dis1*dis2))*r - acos(r/dis1)*r - acos(r/dis2)*r;
        double part2 = sqrt(dis1*dis1-r*r);
        double part3 = sqrt(dis2*dis2-r*r);
        ans = part1 + part2 + part3;
    }    
    finaldis[i][j] = ans;
    finaldis[j][i] = ans;
    return ans;
}

int main() {
    cin >> n >> m;
    cin >> r;
    for (int i = 0; i < n; i++)
        scanf("%lf", &center[i]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            scanf("%lf", &des[i][j]);
        eachdis[i] = dis(des[i], center);
    }
    for (int i = 0; i < m; i++) {
        double ans = 0;
        for (int j = 0; j < m; j++) {
            if(j == i) continue;
            ans += cal(i, j);            
        }
        printf("%.14lf\n", ans);
    }

    return 0;
}