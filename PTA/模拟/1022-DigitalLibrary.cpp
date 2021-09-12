#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<string, set<int>> datalib[6];

int main(){
    int N;
    scanf("%d", &N);
    while (N--) {
        int id;
        string name, author;
        scanf("%d", &id);
        getchar();
        getline(cin, name); // 读入一行
        datalib[0][name].insert(id);
        getline(cin, author);
        datalib[1][author].insert(id);
        string key;
        while(cin >> key) {
            datalib[2][key].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        string print;
        getline(cin, print);
        datalib[3][print].insert(id);
        string date;
        getline(cin, date);
        datalib[4][date].insert(id);
    }
    scanf("%d", &N);
    while (N--) {
        int idx;
        string query;
        scanf("%d: ", &idx);
        getline(cin, query);
        cout << idx << ": " << query << endl;
        if (datalib[idx-1][query].size()) {
            for (auto it = datalib[idx-1][query].begin(); it != datalib[idx-1][query].end(); it++)
                printf("%07d\n", *it);
        } else printf("Not Found\n");
    }
    return 0;
}