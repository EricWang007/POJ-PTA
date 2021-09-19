#include<bits/stdc++.h>
using namespace std;

int main() {
    int d, n;
    scanf("%d%d", &d, &n);
    string tmp = to_string(d);
    for (int i = 0; i < n-1; i++) {
        string next = "";
        int same = 1;
        for (int j = 0; j < tmp.length(); j++) {
            if (j+1 < tmp.length()) {
                if (tmp[j] == tmp[j+1]) {
                    same++;
                } else {
                    next += tmp[j];
                    next += to_string(same);
                    same = 1;
                }
            } else {
                next += tmp[j];
                next += to_string(same);
            }
        }
        tmp = next;
    }    
    cout << tmp << endl;
    return 0;
}
