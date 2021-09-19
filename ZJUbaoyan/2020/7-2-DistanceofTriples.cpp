#include<bits/stdc++.h>
using namespace std;

int N1, N2, N3;
vector<int> S1, S2, S3;
vector<int> ans(3);

int main() {
    scanf("%d%d%d", &N1, &N2, &N3);
    S1.resize(N1);
    S2.resize(N2);
    S3.resize(N3);
    for (int i = 0; i < N1; i++) scanf("%d", &S1[i]);
    for (int i = 0; i < N2; i++) scanf("%d", &S2[i]);
    for (int i = 0; i < N3; i++) scanf("%d", &S3[i]);
    sort(S1.begin(), S1.end(), greater<int>());
    sort(S2.begin(), S2.end(), greater<int>());
    sort(S3.begin(), S3.end(), greater<int>());
    int i = 0, j = 0, k = 0;
    int Min = 0x7fffffff;
    while (i < N1 && j < N2 && k < N3) {
        int tmp = abs(S1[i]-S2[j]) + abs(S1[i]-S3[k]) + abs(S2[j]-S3[k]);
        if (tmp < Min) {
            Min = tmp;
            ans = {S1[i], S2[j], S3[k]};
        }
        if (S1[i] >= S2[j] && S1[i] >= S3[k]) i++;
        else if(S2[j] >= S1[i] && S2[j] >= S3[k]) j++;
        else k++;
    }
     printf("MinD(%d, %d, %d) = %d", ans[0], ans[1], ans[2], Min);
    return 0;
}
