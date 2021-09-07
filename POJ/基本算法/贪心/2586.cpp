#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int s, d, sum;
    while (scanf("%d%d", &s, &d)!=EOF) {
        int i;
        for (i=1; i<5; i++)
            if (d*i > s*(5-i))
                break;
        if (i==5) 
            sum = -1;
        else if (i==4)
            sum = 3*s-9*d;
        else sum = (12-2*i)*s-2*i*d;
        if (sum<0)
            printf("Deficit\n");
        else   printf("%d\n", sum);
    }
    return 0;
}