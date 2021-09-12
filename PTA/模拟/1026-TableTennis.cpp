#include<bits/stdc++.h>
using namespace std;

struct customer {
    int arrive, play, start;
    bool served, vip;
};
struct table {
    int endtime, cnt;
    bool vip;
};

vector<customer> cus_que;
vector<table> tab_que;

bool cmp1(const customer &c1, const customer &c2) {
    return c1.arrive < c2.arrive;
}

bool cmp2(const customer &c1, const customer &c2) {
    return c1.start < c2.start;
}

int findvip(int index, int before) {
    for (int i = index; i < cus_que.size() && cus_que[i].arrive <= before; i++) {
        if (!cus_que[i].served && cus_que[i].vip) return i;
    }
    return -1;
}

void update(int personid, int tableid) {
    cus_que[personid].start = max(cus_que[personid].arrive, tab_que[tableid].endtime);
    cus_que[personid].served = 1;
    tab_que[tableid].endtime = cus_que[personid].start + cus_que[personid].play;
    tab_que[tableid].cnt++;
}

int main(){
    int n, k, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m, s, time, tag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &time, &tag);
        int arrive = h*3600+m*60+s;
        time = time > 120 ? 7200 : time*60;
        cus_que.push_back({arrive, time, 0, false, tag});
    }
    sort(cus_que.begin(), cus_que.end(), cmp1);
    scanf("%d%d", &k, &m);
    for (int i = 0; i < k; i++) tab_que.push_back({28800, 0, 0});
    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);
        tab_que[tmp-1].vip = true;
    }
    for (int i = 0; i < cus_que.size();) { 
        // 找到最先空闲的桌子,如果多个桌子同时空闲，则返回桌子号最小的那个
        int minEnd = INT_MAX, minEndIndex;
        for (int j = 0; j < k; j++) {
            if (minEnd > tab_que[j].endtime) {
                minEnd = tab_que[j].endtime;
                minEndIndex = j;
            }
        }
        if (minEnd >= 21*3600 || cus_que[i].arrive >= 21*3600)
            break;
        int personid = i, tableid = minEndIndex;
        if (minEnd >= cus_que[i].arrive) { //无空闲桌子
            if (tab_que[tableid].vip) { //未来最早空闲的桌子为vip桌，找到队列中在该桌子空闲之前到来的最早的vip
                int vipid = findvip(personid, minEnd);
                if (vipid != -1) personid = vipid;
            } else if (cus_que[i].vip) { //虽然当前的最早空闲且号最小的桌子不是vip，但是还可能存在同时空闲，桌号更大的桌子是vip
                for (int j = 0; j < k; j++) {
                    if (tab_que[j].vip && tab_que[j].endtime == minEnd) {
                        tableid = j;
                        break;
                    }
                }
            }
        } else { //有空闲桌子
            for (int j = 0; j < k; j++) { //找到桌号最小的空闲桌
                if (tab_que[j].endtime <= cus_que[personid].arrive) {
                    tableid = j;
                    break;
                }
            }
            if (cus_que[personid].vip) {
                for(int j = 0; j < k; j++){       //寻找最小的空闲的vip桌子
                    if(tab_que[j].vip && tab_que[j].endtime <= cus_que[personid].arrive){
                        tableid = j;
                        break;
                    }
                }
            }
        }
        update(personid, tableid);
        while (i < cus_que.size() && cus_que[i].served) ++i;
    }
    sort(cus_que.begin(), cus_que.end(), cmp2);
    for (int i = 0; i < cus_que.size(); i++) {
        if (cus_que[i].served) {
            int wait = cus_que[i].start - cus_que[i].arrive;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",cus_que[i].arrive/3600,cus_que[i].arrive%3600/60,cus_que[i].arrive%60,\
            cus_que[i].start/3600,cus_que[i].start%3600/60,cus_que[i].start%60, (int)(1.0*wait/60+0.5));
        }
    }
    for (int i = 0; i < k; i++) printf("%d%c", tab_que[i].cnt, i==k-1?'\n':' ');
    return 0;
}