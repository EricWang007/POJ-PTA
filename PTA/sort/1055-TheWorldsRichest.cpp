#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct person {
    string name;
    int age;
    int money;
};
vector<person> plist, cdm_plist;
int book[205]={0};
int N, K;

bool cmp(const person & p1, const person & p2) {
    if (p1.money == p2.money)
        return p1.age == p2.age ? p1.name < p2.name : p1.age < p2.age;
    return p1.money > p2.money;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        person tmp;
        cin >> tmp.name >> tmp.age >> tmp.money;
        plist.push_back(tmp);
    }
    sort(plist.begin(), plist.end(), cmp);
    for (int i = 0; i < N; i++) {
        if (book[plist[i].age] < 100) {
            book[plist[i].age]++;
            cdm_plist.push_back(plist[i]);
        }
    }
    for (int i = 1; i <= K; i++) {
        int x, amin, amax;
        scanf("%d%d%d", &x, &amin, &amax);
        printf("Case #%d:\n", i);
        int cnt = 0;
        for (auto it : cdm_plist) {
            if (amin <= it.age && it.age <= amax) {
                cout << it.name << " " << it.age << " " << it.money << endl;
                cnt++;
            }
            if (cnt == x) break;
        }
        if (cnt == 0) printf("None\n");
    }
    return 0;
}