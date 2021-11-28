/*20分*/
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

long long eng[100005][3]={0};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int L, R;
            long long a, b, c;
            cin >> L >> R >> a >> b >> c;
            for (int j = L; j <= R; j++) {
                eng[j][0] = (eng[j][0]+a)%M;
                eng[j][1] = (eng[j][1]+b)%M;
                eng[j][2] = (eng[j][2]+c)%M;
            }
        } else if (op == 2) {
            int L, R;
            long long k;
            cin >> L >> R >> k;
            for (int j = L; j <= R; j++) {
                eng[j][0] = (eng[j][0]*k)%M;
                eng[j][1] = (eng[j][1]*k)%M;
                eng[j][2] = (eng[j][2]*k)%M;
            }
        } else if (op == 3) {
            int L, R;
            cin >> L >> R;
            for (int j = L; j <= R; j++) {
                int tmp = eng[j][0];
                eng[j][0] = eng[j][1];
                eng[j][1] = eng[j][2];
                eng[j][2] = tmp;
            }
        } else if (op == 4) {
            int L, R;
            cin >> L >> R;
            long long s1=0, s2=0, s3=0;
            for (int j = L; j <= R; j++) {
                s1 = (s1+eng[j][0])%M;
                s2 = (s2+eng[j][1])%M;
                s3 = (s3+eng[j][2])%M;
            }
            cout << (long long)((s1*s1)%M+(s2*s2)%M+(s3*s3)%M)%M << endl;
        }
    }
    return 0;
}