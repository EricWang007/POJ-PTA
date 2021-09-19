#include<bits/stdc++.h>
using namespace std;

bool judge(string str) {
    int l = 0, r = str.length()-1;
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++; r--;
    }
    return true;
}

string change(string str) {
    string ans="";
    int n = str.length()-1;
    int c=0;
    for (int i = 0; i < str.length(); i++) {
        int sum = str[i]-'0' + str[n-i]-'0'+c;
        ans += sum%10+'0';
        c = sum/10;
    }
    if (c) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string ori;
    cin >> ori;
    int cnt = 0;
    while (!judge(ori)) {
        if (cnt >= 10) break;
        string rev = ori;
        reverse(rev.begin(), rev.end());
        string newstr = change(ori);
        printf("%s + %s = %s\n", ori.c_str(), rev.c_str(), newstr.c_str());
        ori = newstr;
        cnt ++;
    }
    if (judge(ori)) printf("%s is a palindromic number.", ori.c_str());
    else printf("Not found in 10 iterations.");
    return 0;
}