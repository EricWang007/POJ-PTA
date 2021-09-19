#include <bits/stdc++.h>
using namespace std;

vector<string> input(10001);

bool cmp(const string &s1, const string &s2) {
    return s1+s2 < s2+s1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.begin()+n, cmp);
    string out="";
    for (int i = 0; i < n; i++) {
        out += input[i];
    }
    int i;
    for (i = 0; i < out.size() && out[i] == '0'; i++) ;
    if (i == out.size()) cout << "0";
    cout << out.substr(i);
    return 0;
}