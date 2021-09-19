#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct station {
    double price;
    int dis;
};

int C, D, Davg, N;
vector<station> stations;

bool cmp(const station & s1, const station & s2) {
    return s1.dis < s2.dis;
}

int main(){
    scanf("%d%d%d%d", &C, &D, &Davg, &N);
    while (N--) {
        double f;
        int dis;
        scanf("%lf %d", &f, &dis);
        stations.push_back({f, dis});
    }
    sort(stations.begin(), stations.end(), cmp);
    double total = 0;
    int next = 0;
    double lastprice = 0x7fffffff;
    vector<station>::iterator it = stations.begin();
    while(it != stations.end()) {
        if (next < it->dis) break;
        if (it->price <= lastprice) {            
            total -= (next - it->dis)/(double)Davg * lastprice;
            int newnext = min(it->dis + C*Davg, D);
            total += it->price * (newnext - it->dis)/(double)Davg;
            next = newnext;
            lastprice = it->price;
        } else if((it + 1 == stations.end() && next < D) || \
        (it + 1 != stations.end() && next < (it+1)->dis)) {
            int newnext = min(it->dis + C*Davg, D);
            total += (newnext-next)/(double)Davg * it->price;
            next = newnext;
            lastprice = it->price;
        }
        it++;
    }
    if (next < D) {
        printf("The maximum travel distance = %.2lf", (double)next);
        return 0;
    }
    printf("%.2lf", total);
    return 0;
}