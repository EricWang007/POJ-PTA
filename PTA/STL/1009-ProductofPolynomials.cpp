#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int, double, greater<int>> A, out;
    int n;
    scanf("%d", &n);
    while (n--) {
        int ex;
        double co;
        scanf("%d%lf", &ex, &co);
        A[ex] = co;
    }
    scanf("%d", &n);
    while (n--) {
        int ex;
        double co;
        scanf("%d%lf", &ex, &co);
        map<int, double>::iterator i = A.begin();
        while (i != A.end()) {
            int sum = i->first + ex;
            double mul = i->second * co;
            out[sum] += mul; 
            if (out[sum] == 0)
                out.erase(sum);
            i++;
        }
    }
    map<int, double>::iterator i = out.begin();
    printf("%d", out.size());
    while (i != out.end()) {
        printf(" %d %.1lf", i->first, i->second);
        i++;
    }
    return 0;
}