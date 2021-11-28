#include <bits/stdc++.h>
using namespace std;
#define INF 9e18
#define SIZE 1000010

struct folder {
    long long child_limit = INF;
    long long total_limit = INF;
    long long child_size = 0;
    long long total_size = 0;    
} folders[SIZE];

unordered_map<string, int> child_folder[SIZE];
unordered_map<string, int> file[SIZE];

int cnt = 0;

void split(vector<string> &res, string str) {
    int i = 1;
    int j = i;
    while (i < str.length()) {
        while (j < str.length() && str[j] != '/') j++;
        res.push_back(str.substr(i, j-i));
        j++;
        i = j;
    }
}

long long dfsdelete(int cur) {
    long long sum = 0;
    for (auto &it : file[cur]) sum += it.second;
    file[cur].clear();
    for (auto &it : child_folder[cur])
        sum += dfsdelete(it.second);
    child_folder[cur].clear();
    return sum;
}

void changesize(vector<string> &res, long long size) {
    int ressize = res.size();
    int cur = 0;
    for (int i = 0; i < ressize-1; i++) {
        folders[cur].total_size += size;
        cur = child_folder[cur][res[i]];
    }
    folders[cur].child_size += size;
    folders[cur].total_size += size;
}

void rollback(vector<int> &newfolder_1, vector<string> &newfolder_2) {
    int n = newfolder_1.size();
    for (int i = 0; i < n; i++) {
        int cur = newfolder_1[i];
        string next = newfolder_2[i];
        child_folder[cur].erase(next);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        string path;
        long long size, LD, LR;
        cin >> c;
        if (c == 'C') {
            cin >> path >> size;
            vector<string> res;
            split(res, path);
            int cur = 0;
            bool flag = false;
            long long minitotalpace = INF, minichildspace = INF;
            int ressize =  res.size();
            vector<int> newfolder_1;
            vector<string> newfolder_2;
            for (int i = 0; i < ressize-1; i++) {
                if (folders[cur].total_limit != INF)
                    minitotalpace = min(minitotalpace, folders[cur].total_limit-folders[cur].total_size);
                if (child_folder[cur].count(res[i]) == 0) {
                    if (file[cur].count(res[i]) == 0) { 
                        //创建新文件夹
                        newfolder_1.push_back(cur);
                        newfolder_2.push_back(res[i]);
                        child_folder[cur][res[i]] = ++cnt;
                        cur = cnt;
                    } else {
                        flag = true;
                        break;
                    } 
                } else {
                    cur = child_folder[cur][res[i]];  
                }   
            }
            if (folders[cur].total_limit != INF)
                minitotalpace = min(minitotalpace, folders[cur].total_limit-folders[cur].total_size);
            if (folders[cur].child_limit != INF)
                minichildspace = min(minichildspace, folders[cur].child_limit-folders[cur].child_size);
            if (flag) {
                rollback(newfolder_1, newfolder_2); 
                cout << 'N' << endl;
            }
            else {
                int newsize = size;
                if (file[cur].count(res[ressize-1]) == 0) {
                    if (child_folder[cur].count(res[ressize-1]) != 0) {
                        rollback(newfolder_1, newfolder_2); 
                        cout << 'N' << endl;
                        continue;
                    }
                    else size -= file[cur][res[ressize-1]];
                } else size -= file[cur][res[ressize-1]];
                if (size < min(minichildspace, minitotalpace)) {
                    file[cur][res[ressize-1]] = newsize;
                    cout << "Y" << endl;
                    changesize(res, size);
                } else {
                    rollback(newfolder_1, newfolder_2); 
                    cout << 'N' << endl;
                }
            }
        } else if (c == 'R') {
            cin >> path;
            cout << "Y" << endl;
            vector<string> res;
            split(res, path);
            int cur = 0;
            int ressize = res.size();
            bool flag = false;
            for (int i = 0; i < ressize-1; i++) {
                if (child_folder[cur].count(res[i]))
                    cur = child_folder[cur][res[i]];
                else {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            long long totalsize = 0;
            if (file[cur].count(res[ressize-1]) != 0) { //存在文件
                totalsize = file[cur][res[ressize-1]];
                file[cur].erase(res[ressize-1]);
            }
            else if (child_folder[cur].count(res[ressize-1]) != 0) { //存在文件夹
                int newcur = child_folder[cur][res[ressize-1]];
                totalsize = dfsdelete(newcur);
                child_folder[cur].erase(res[ressize-1]);
            } else continue;
            cur = 0;
            for (int i = 0; i < res.size()-1; i++) {
                folders[cur].total_size -= totalsize;
                cur = child_folder[cur][res[i]];
            }
            folders[cur].total_size -= totalsize;
        } else if (c == 'Q') {
            cin >> path >> LD >> LR;
            vector<string> res;
            split(res, path);
            int cur = 0;
            bool flag = false;
            for (int i = 0; i < res.size(); i++) {
                if (child_folder[cur].count(res[i]) != 0)
                    cur = child_folder[cur][res[i]];
                else {
                    flag = true;
                    break;
                }
            }
            if (flag) cout << "N" << endl;
            else {
                if ((LD != 0 && LD < folders[cur].child_size) || (LR != 0 && LR < folders[cur].total_size)) {
                    cout << "N" << endl;
                    continue;
                }
                if (LD == 0) folders[cur].child_limit = INF;
                else if (LD >= folders[cur].child_size) folders[cur].child_limit = LD;
                if (LR == 0) folders[cur].total_limit = INF;
                else if (LR >= folders[cur].total_size) folders[cur].total_limit = LR;    
                cout << "Y" << endl;          
            }
        }
    }
    return 0;
}