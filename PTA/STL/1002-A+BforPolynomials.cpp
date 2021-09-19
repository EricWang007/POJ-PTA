#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, double, greater<int>> p1;
    int n1, n2;
    scanf("%d", &n1);
    while (n1--) {
        int e;
        double c;
        scanf("%d %lf", &e, &c);
        p1[e] = c;
    }
    scanf("%d", &n2);
    while (n2--) {
        int e;
        double c;
        scanf("%d%lf", &e, &c);
        p1[e] += c;
        if (p1[e] == 0) p1.erase(e);
    }
    printf("%d", p1.size());
    for (auto it : p1)
        printf(" %d %.1lf", it.first, it.second);
    return 0;
}