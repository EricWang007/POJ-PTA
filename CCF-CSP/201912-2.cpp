#include <bits/stdc++.h>

using namespace std;

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

set<pair<int, int>> points;

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int dir1[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int dir2[4][2] = {{1,1},{-1,-1},{1,-1},{-1,1}};
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.insert(make_pair(x, y));
    }
    int ans[5]={0};
    for (auto &it: points) {
        int x = it.first, y = it.second;
        int x1, y1, cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < 4; j++) {
            x1 = x + dir1[j][0];
            y1 = y + dir1[j][1];
            if (points.count(make_pair(x1, y1)))
                cnt1++;
        }
        if (cnt1 == 4) {
            for (int j = 0; j < 4; j++) {
                x1 = x + dir2[j][0];
                y1 = y + dir2[j][1];
                if (points.count(make_pair(x1, y1)))
                    cnt2++;
            }
            ans[cnt2]++;
        }
    }
    for (int i = 0; i < 5; i++)
         cout << ans[i] << endl;
    return 0;
}
