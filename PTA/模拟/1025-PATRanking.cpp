#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct testee {
    string id;
    int score, loc;
    int rank[2];
};

vector<testee>arr(30005);
int n;

bool cmp(const testee &t1, const testee &t2) {
    return t1.score == t2.score ? t1.id < t2.id : t2.score < t1.score;
}

void my_rank(int f, int l, int r) {
    int ranks = 1;
    if (f > l) return ;
    arr[f].rank[r] = ranks;
    ranks++;
    f++;
    while (f < l) {
        if (arr[f].score == arr[f-1].score) arr[f].rank[r] = arr[f-1].rank[r];
        else arr[f].rank[r] = ranks;
        ranks ++;
        f++;
    }
}

int main(){
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        int k, idx = 0;
        scanf("%d", &k);
        while (idx < k) {
            testee tmp;
            cin >> tmp.id;
            scanf("%d", &tmp.score);
            tmp.loc = i;
            arr[m+idx] = tmp;
            idx++;
        }
        sort(arr.begin()+m, arr.begin()+m+k, cmp);
        my_rank(m, m+k, 0);
        m += k;
    }
    sort(arr.begin(), arr.begin()+m, cmp);
    my_rank(0, m, 1);
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        cout << arr[i].id << " ";
        printf("%d %d %d\n", arr[i].rank[1], arr[i].loc, arr[i].rank[0]);
    }
    return 0;
}