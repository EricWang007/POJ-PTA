#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;

struct customer{
    double arrive_time;
    double handle_time;
    customer(){};
    customer(double time1, double time2) {
        arrive_time = time1;
        handle_time = time2;
    };
    bool operator<(const customer& c) const {
        return arrive_time >= c.arrive_time; //小顶堆
    }
};

int main(){
    double sum = 0;
    scanf("%d%d", &n, &k);
    priority_queue<customer> que;
    vector<int> windows;
    windows.resize(k, 8*60*60);
    
    //进入队列
    for (int i = 0; i < n; i++) {
        int h, m, s, hand;
        scanf("%d:%d:%d %d", &h, &m, &s, &hand);
        double arr = h * 3600 + m * 60 + s;
        if (arr <= 17 * 3600) {
            que.push(customer(arr, hand*60));
        }
    }
    double all = que.size();
    //更新
    while (que.size()) { 
        double min = 0x7fffffff;
        int j = 0;
        for (int i = 0; i < k; i++) {
            if (windows[i] < min) {
                min = windows[i];
                j = i;
            }
        }
        customer cus = que.top();
        que.pop();
        if (cus.arrive_time > windows[j]) {
            windows[j] = cus.arrive_time + cus.handle_time;
        } else {
            sum += windows[j] - cus.arrive_time;
            windows[j] += cus.handle_time;
        }
    }
    printf("%.1lf", sum/60/all);
    return 0;
}