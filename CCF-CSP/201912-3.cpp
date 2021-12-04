#include <bits/stdc++.h>

using namespace std;

map<string, int> mm;
int head = 0;
int cnt1[1000], cnt2[1000];
bool flag = true;

//string to_string(int i) {
//    string str="";
//    while (i) {
//        str += '0'+i%10;
//        i /= 10;
//    }
//    reverse(str.begin(), str.end());
//    return str;
//}
//
//int stoi(string str) {
//    int ans = 0;
//    for (int i = 0; i<str.length(); i++) {
//        ans *= 10;
//        ans += str[i]-'0';
//    }
//    return ans;
//}

void split(string str, vector<string> &res) {
    int idx = 0, n = str.length();
    while (idx < n) {
        int j = idx;
        while (j < n && str[j] != '+') j++;
        res.push_back(str.substr(idx, j-idx));
        idx = j+1;
    }
}

int trans(string formula, int b, map<int, int> &elements) {
    int n = formula.length();
    while (b < n) {
        if (formula[b] == ')') {
            return b+1;
        }
        map<int, int> tmp;
        if (formula[b] == '(')
            b = trans(formula, b+1, tmp); //解析完()里的内容
        else if ('A' <= formula[b] && formula[b] <= 'Z') {
            string element="";
            int idx;
            element += formula[b];
            b++;
            if (b < n && 'a' <= formula[b] && formula[b] <= 'z') {
                element += formula[b];
                b++;
            }
            if (mm.count(element)) idx = mm[element];
            else {
                mm[element] = head;
                idx = head;
                head++;
            }
            tmp[idx] = 1;
        }

        int coef = 0;
        int i = b;
        while (i < n && ('0' <= formula[i] && formula[i] <= '9'))
            i++;
        if (i == b) coef = 1;
        else coef = stoi(formula.substr(b, i-b));
        b = i;

        for (auto &it : tmp) {
            it.second *= coef;
            if (elements.count(it.first)) elements[it.first] += it.second;
            else elements[it.first] = it.second;
        }
    }
    return b;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    string equa;
    for (int i = 0; i < n; i++) {
        cin >> equa;
        int idx = equa.find("=");
        string left = equa.substr(0, idx);
        string right = equa.substr(idx+1);
        vector<string> left_res, right_res;
        split(left, left_res);
        split(right, right_res);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        head = 0;
        mm.clear();
        for (string &expr: left_res) {
            int coef = 0;
            int nn = expr.length();
            int i = 0;
            while (i < nn && ('0' <= expr[i] && expr[i] <= '9'))
                i++;
            if (i == 0) coef = 1;
            else coef = stoi(expr.substr(0, i));
            string formula = expr.substr(i);
//            cout << formula << endl;
            map<int, int> elements;
            trans(formula, 0, elements);
            for (auto &it : elements)
                cnt1[it.first] += coef * it.second;
        }
        for (string &expr: right_res) {
            int coef = 0;
            int n = expr.length();
            int i = 0;
            while (i < n && ('0' <= expr[i] && expr[i] <= '9'))
                i++;
            if (i == 0) coef = 1;
            else coef = stoi(expr.substr(0, i));
            string formula = expr.substr(i);
            map<int, int> elements;
            trans(formula, 0, elements);
            for (auto &it : elements)
                cnt2[it.first] += coef * it.second;
        }
        int p = 0;
        for (p = 0; p < head; p++) {
            if (cnt1[p] != cnt2[p]) {
                cout << "N" << endl;
                break;
            }
        }
        if (p == head) cout << "Y" << endl;
    }


    return 0;
}
