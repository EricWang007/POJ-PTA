#include<bits/stdc++.h>
using namespace std;

unordered_set<int> digits;

int change(int tmp) {
    int ans = 0;
    while (tmp) {
        int d = tmp%10;
        ans += d*d;
        tmp/=10;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1) printf("0\n");
        else {
            int cnt = 0;
            while (tmp != 1) {
                if (digits.count(tmp)) {
                    printf("%d\n", tmp);
                    break;
                }
                digits.insert(tmp);
                cnt++;
                tmp = change(tmp);
            }
            if (tmp == 1) printf("%d\n", cnt);
        }
        digits.clear();
    }
    return 0;
}