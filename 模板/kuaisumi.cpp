#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double Power(double base, int exponent) {
    if (exponent >= 0) {
        double ans = 1.0;
        while (exponent) {
            if (exponent & 1) // 奇数
                ans = ans * base;
            base = base * base;
            exponent = exponent >> 1;
        }
        return ans;
    } else return 1.0 / Power(base, -1 * exponent);
}


int main(){
    printf("%lf", Power(2.5, 8));

    return 0;
}