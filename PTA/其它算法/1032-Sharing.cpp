#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

map<int, int> addrs;

int main(){
    int start1, start2, n;
    scanf("%d%d%d", &start1, &start2, &n);
    while(n--) {
        int start, end;
        char c;
        scanf("%d %c %d", &start, &c, &end);
        addrs[start] = end;
    }
    int idx1 = start1, idx2 = start2;
    while (idx1 != idx2) {
        idx1 = idx1 == -1 ? start2 : addrs[idx1];
        idx2 = idx2 == -1 ? start1 : addrs[idx2];
    }
    if (idx1 == -1) printf("-1");
    else printf("%05d", idx1);
    return 0;
}