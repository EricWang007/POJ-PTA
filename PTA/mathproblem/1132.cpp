#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        string input;
        cin >> input;
        int n = input.length();
        long long a = stoll(input.substr(0, n/2));
        long long b = stoll(input.substr(n/2, n));
        if (a == 0 || b == 0) printf("No\n");
        else if(stoll(input) % (a*b) == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}