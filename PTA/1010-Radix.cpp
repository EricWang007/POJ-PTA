#include <iostream>
#include <string>
using namespace std;

long long chartoint (char c) {
    if ('0' <= c && c <= '9')
        return c-'0';
    else return c-'a'+10;
}

long long todecimal(string s, long long r) {
    long long sum = 0;
    long long ex = 1;
    for (int i = s.length()-1; i >= 0; i--) {
        long long digit = chartoint(s[i]);
        if (digit >= r) return -1;
        sum += digit * (long long)ex;
        ex *= r;
        if (sum < 0 || ex < 0)
            return -2;
    }    
    return sum;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int tag;
    long long r1;
    scanf("%d%lld", &tag, &r1);
    long long sum = tag == 1 ? todecimal(s1, r1) : todecimal(s2, r1);
    
    // 二分法
    long long low = 2, high = sum+1;
    while (low <= high) {
        long long mid = (low+high)/2;
        long long sum2 = tag == 1 ? todecimal(s2, mid) : todecimal(s1, mid);
        if (sum2 > sum || sum2 == -2) high = mid-1;
        else if (sum2 == -1 || sum2 < sum) low = mid + 1;
        else if (sum2 == sum) {
            printf("%lld", mid);
            return 0;
        }
    }
    
    // 非二分法
//     for (long long r = 1; r <= sum+1; r++) {
//         long long sum2 = tag == 1 ? todecimal(s2, r) : todecimal(s1, r);
//         if (sum2 == -1) continue;
//         else if (sum2 > sum || sum2 == -2) {
//             printf("Impossible");
//             return 0;
//         } else if (sum2 == sum) {
//             printf("%lld", r);
//             return 0;
//         } 
//     }
    
    printf("Impossible");
    return 0;
}