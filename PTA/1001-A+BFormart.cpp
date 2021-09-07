#include <iostream>
#include <stack>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int res = a+b;
    stack<int> stk;
    if (res < 0) {
        printf("-");
        res = -res;
    }
    do {
        stk.push(res%1000);
        res /= 1000;
    }
    while(res) ;
    printf("%d", stk.top());
    stk.pop();
    while (stk.size()) {
        printf(",%03d", stk.top()); // 打印3位，不足的高位用0填充
        stk.pop();
    }
    return 0;
}