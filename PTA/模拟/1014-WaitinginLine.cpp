#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k ,q;

struct customer{
    int time;
    int num;
    customer(int _time, int _num) {
        time = _time;
        num = _num;
    }
};

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &q);
    int time[2000];
    int finish[1000][2] = {0};
    vector<customer> windows[20];
        
    for (int i = 0; i < k; i++) {
        scanf("%d", &time[i]);
    }
    int idx = 0;
    for (int i = 0; i < m && idx < k; i++)
        for (int j = 0; j < n && idx < k; j++) {
            windows[j].push_back(customer(time[idx], idx));
            idx++;
        }
    int h = 8, m = 0;

    while (h < 17) {
        int min = 0x7fffffff;
        int empty = 0;
        for (int i = 0; i < n; i++) {
            if (windows[i].size()) {
                if (windows[i][0].time < min) {
                    min = windows[i][0].time;
                }
            }
            else empty++;
        }
        if (empty == n) break;
        //更新时间
        m += min;
        while (m >= 60) {
            m -= 60;
            h++;
        }
        if (h >= 17) {
            for (int i = 0; i < n; i++) {
                if (windows[i].size() > 0) { //这一部分容易错
                    int tmpm = m + windows[i][0].time - min;
                    int tmph = h; 
                    while (tmpm >= 60) {
                        tmpm -= 60;
                        tmph++;
                    }
                    finish[windows[i][0].num][0] = tmph;
                    finish[windows[i][0].num][1] = tmpm;
                }
            }
            break;
        }
        //更新队伍
        for (int i = 0; i < n; i++) {
            if (windows[i].size() > 0) {
                windows[i][0].time -= min;
                if (windows[i][0].time == 0) {
                    finish[windows[i][0].num][0] = h;
                    finish[windows[i][0].num][1] = m;
                    windows[i].erase(windows[i].begin());
                    if (idx < k) {
                        windows[i].push_back(customer(time[idx], idx));
                        idx++;
                    }
                }
            }
        }
    }   

    while (q--) {
        int tmp;
        scanf("%d", &tmp);
        if (finish[tmp-1][0] == 0)
            printf("Sorry\n");
        else printf("%02d:%02d\n", finish[tmp-1][0], finish[tmp-1][1]);
    }

    return 0;
}