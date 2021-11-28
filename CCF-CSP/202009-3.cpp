#include <bits/stdc++.h>
using namespace std;

struct device {
    string op;
    bool out;
    bool checked;
    bool res;
    vector<char> in_type; // 0 signal, 1 output
    vector<int> in_num;
} devices[505];
vector<vector<int>> in;
int ans[10005];
int M, N;

bool loop(int i) {
    if (devices[i].checked) return true;
    if (devices[i].res == true) return false;
    devices[i].res = true;
    int n = devices[i].in_type.size();
    for (int j = 0; j < n; j++) {
        if (devices[i].in_type[j] == 'I') continue;
        if (!loop(devices[i].in_num[j])) return false;
    }
    devices[i].checked = true;
    return true;
}

bool check_loop() {
    for (int i = 1; i <= N; i++) {
        devices[i].checked = false;
        devices[i].res = false;
    }
    for (int i = 1; i <= N; i++) {        
        if (!loop(i)) return false;
    }
    return true;
}

bool cal(int j, int num) {
    if (devices[num].res) return devices[num].out;
    int n = devices[num].in_type.size();
    string op = devices[num].op;
    bool ans = 0;
    if (op == "NOT" || op == "AND" || op == "NAND") ans = 1;
    for (int i = 0; i < n; i++) {
        int tmp;
        if (devices[num].in_type[i] == 'I') tmp = in[j][devices[num].in_num[i]];
        else tmp = cal(j, devices[num].in_num[i]);
        if (op == "NOT") ans = !tmp;
        else if (op == "AND") ans &= tmp;
        else if (op == "OR") ans |= tmp;
        else if (op == "XOR") ans ^= tmp;
        else if (op == "NAND") ans &= tmp;
        else if (op == "NOR") ans |= tmp;
    }
    if (op == "NAND" || op == "NOR") ans = !ans;
    devices[num].res = true;
    devices[num].out = ans;
    return ans;
}

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> M >> N;
        for (int j = 1; j <= N; j++) {
            int k;
            cin >> devices[j].op >> k;
            devices[j].in_type.resize(k);
            devices[j].in_num.resize(k);
            for (int t = 0; t < k; t++)
                cin >> devices[j].in_type[t] >> devices[j].in_num[t];
        }
        bool flag = check_loop();
        // PART 2
        int S;
        cin >> S;
        in.resize(S);
        for (int j = 0; j < S; j++) {
            in[j].resize(M+1);
            for (int t = 1; t <= M; t++)
                cin >> in[j][t];
        }
        for (int j = 0; j < S; j++) {
            int si;
            cin >> si;
            for (int k = 1; k <= si; k++)
                cin >> ans[k];
            if (flag) {
                // 模拟
                for (int k = 1; k <= N; k++) devices[k].res = false;
                for (int k = 1; k <= si; k++) {
                    if (cal(j, ans[k])) 
                        cout << 1;
                    else cout << 0;
                    if (k == si) cout << endl;
                    else cout << " ";
                }
            }
        }
        if (!flag) 
            cout << "LOOP" << endl;
    }
    return 0;
}