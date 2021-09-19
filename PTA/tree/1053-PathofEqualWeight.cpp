#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, S;
int weight[105];
vector<int> nodes[105];
vector<int> ans;

bool cmp(const int &a, const int &b) {
    return weight[b] < weight[a];
}

void dfs(int root, int sum) {
    if (sum > S) return;
    ans.push_back(weight[root]);
    if (nodes[root].size() == 0) {
        if (sum == S) {
            for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
                printf("%d%c", *it, it+1==ans.end() ? '\n' : ' ');
        }
        ans.pop_back();
        return;
    }
    vector<int>::iterator it = nodes[root].begin();
    while (it != nodes[root].end()) { 
        dfs(*it, sum + weight[*it]);        
        it++;
    }
    ans.pop_back();
}

int main(){
    scanf("%d%d%d", &N, &M, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < M; i++) {
        int id, num;
        scanf("%d%d", &id, &num);
        while (num--) {
            int k = 0;
            scanf("%d", &k);
            nodes[id].push_back(k);            
        }
        sort(nodes[id].begin(), nodes[id].end(), cmp);
    }
    dfs(0, weight[0]);
    return 0;
}