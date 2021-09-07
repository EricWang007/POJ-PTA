#include<iostream>
#include<string>

using namespace std;
// 注意，本题由于需要记录起始位置，所以要记录last_start和start
// last_start: 以上一个元素为结尾的最长字串的起始位置
// start: 最长字串的起始位置
// end: 最长字串的结束位置
// first: 第一个元素
// Last：最后一个元素

int main(){
    int n;
    scanf("%d", &n);
    int start = 0, end = 0, last = -1, last_start = 0, Max = 0x80000000;
    int first, Last;
    while (n--) {
        int tmp;
        scanf("%d", &tmp);
        if (Max == 0x80000000) first = tmp;
        if (n == 0) Last = tmp;
        if (last < 0) {
            last = tmp;
            if (last > Max) {
                Max = last;
                start = tmp;
                end = tmp;
            }
            last_start = tmp;
        } else {
            last = last+tmp;
            if (last > Max) {
                Max = last;
                end = tmp;
                start = last_start;
            }
        }
    }
    if (Max < 0) printf("0 %d %d", first, Last);
    else printf("%d %d %d", Max, start, end);
    
    return 0;
}