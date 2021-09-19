#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int res = a+b;
    vector<int> stk;
    if (res < 0) {
        printf("-");
        res = -res;
    }
    do {
        stk.push_back(res%1000);
        res /= 1000;
    }
    while(res) ;
    printf("%d", stk.back());
    stk.pop_back();
    while (stk.size()) {
        printf(",%03d", stk.back()); // 打印3位，不足的高位用0填充
        stk.pop_back();
    }
    return 0;
}