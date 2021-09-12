#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool palin(string str) {
    int l = 0, r = str.length()-1;
    while (l <= r) {
        if (str[l] != str[r]) return false;
        l++;
        r--;
    }
    return true;
}

void add(string &str) {
    string output = "";
    int n = str.length();
    int c = 0;
    for (int i = 0; i < n; i++) {
        int sum = str[i]-'0' + str[n-1-i]-'0' + c;
        output += '0' + sum%10;
        c = sum / 10;
    }
    if (c) output += '0' + c%10;
    reverse(output.begin(), output.end());
    str = output;
}

int main(){
    string input;
    int k, cnt =0;
    cin >> input;
    scanf("%d", &k);
    while (!palin(input)) {
        cnt++;
        if (cnt > k) break;
        add(input);
    }
    if (cnt > k) {
        cout << input << endl;
        printf("%d", k);
    } else {
        cout << input << endl;
        printf("%d", cnt);
    }
}