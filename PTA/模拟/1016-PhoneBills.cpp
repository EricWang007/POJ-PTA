#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rec {
    int M, D, H, m;
    bool tag;
    rec(int a, int b, int c, int d, bool t) {
        M = a;
        D = b;
        H = c;
        m = d;
        tag = t;
    };
};

int toll[25], rate[25]; //小时费用和累计费用
map<string, vector<rec>>R;
double all = 0;

bool cmp(rec &a, rec &b) {
    return a.D*24*60 + a.H*60 + a.m < b.D*24*60 + b.H*60 + b.m;
}

void tolls(rec &a, rec &b) {
    printf("%02d:%02d:%02d %02d:%02d:%02d ", a.D, a.H, a.m, b.D, b.H, b.m);
    printf("%d ", (b.D-a.D)*24*60+(b.H-a.H)*60+b.m-a.m);
    double x = (b.D-a.D)*rate[24]*60 + (rate[b.H]- rate[a.H])*60 + toll[b.H]*b.m - toll[a.H]*a.m;
    printf("$%.2lf\n", x/100.00);
    all += x;
}

int main(){
    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
        rate[i+1] = rate[i] + toll[i];
    }
    int N;
    scanf("%d", &N);
    while (N--) {
        string id, tag;
        bool t;
        int m, d, h, s;
        cin >> id;
        scanf("%d:%d:%d:%d", &m, &d, &h, &s);
        cin >> tag;
        tag == "on-line" ? t = 1 : t = 0;
        R[id].push_back(rec(m, d, h, s, t));
    }
    map<string, vector<rec>>::iterator it = R.begin();
    while (it != R.end()) {
        all = 0;
        bool flag = false;
        sort(it->second.begin(), it->second.end(), cmp);
        int n = it->second.size();
        for (int i = 0; i < n; i++) {
            if (it->second[i].tag) {
                int j = i + 1;
                while (j < n && it->second[j].tag) {++i; ++j;}
                if (j < n) {
                    if (!flag) printf("%s %02d\n", it->first.c_str(), it->second[i].M);
                    tolls(it->second[i], it->second[j]);
                    ++i; flag = 1;
                }
            }
        }
        if (flag) printf("Total amount: $%.2lf\n", all/100.00);
        ++it;
    }
    return 0;
}