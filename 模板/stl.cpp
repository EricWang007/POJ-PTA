#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

struct mystruct {
    int a;
    int b;    
    mystruct(int c, int d) {a = c; b = d;};
    bool operator<(const mystruct &m1) const {
        return a >= m1.a; //从大到小排序
    }
};

struct mystruct2 {
    int a;
    int b;
    mystruct2(){};
    mystruct2(int c, int d) {a = c; b = d;};
};

/* map：默认从小到大排序（红黑树）
   unordered_map：不排序（哈希表） */    
void try_map() { 
    unordered_map<string, int> mymap;
    //插入
    mymap["111"] = 3; //可以覆盖
    mymap.insert(pair<string, int>("111", 2)); //无法覆盖
    printf("%d\n", mymap["111"]);
    //查找
    auto iter = mymap.find("111");
    if (iter != mymap.end())
        printf("%d", iter->second);
    //删除
    mymap.erase(iter);
    mymap.erase("123");
    mymap.clear();
}

/* set：默认从小到大排序（红黑树） */
void try_set() { 
    set<int> myset;
    //插入
    myset.insert(1);
    //查找
    if (myset.count(1) > 0)
        printf("Exist\n");
    //删除
    myset.erase(1);
    //自定义比较器
    set<mystruct> newset;
    newset.insert(mystruct(10, 2));
    newset.insert(mystruct(3, 2));
    newset.insert(mystruct(4, 2));
    for (auto it = newset.begin(); it != newset.end(); it++) {
        printf("%d %d\n", it->a, it->b);
    }
}

// 自定义比较函数
bool cmp(const mystruct2 & m1, const mystruct2 & m2) {
    return m1.a > m2.a;
}
void try_sort() {
    vector<mystruct2> newset;
    newset.push_back(mystruct2(10, 2));
    newset.push_back(mystruct2(3, 2));
    newset.push_back(mystruct2(4, 2));
    sort(newset.begin(), newset.end(), cmp);
    for (auto it = newset.begin(); it != newset.end(); it++) 
        printf("%d %d\n", it->a, it->b);
    
    mystruct2 newset2[100];
    newset2[0] = mystruct2(10, 2);
    newset2[1] = mystruct2(3, 2);
    newset2[2] = mystruct2(4, 2);
    sort(newset2, newset2+3, cmp);
    for (int i = 0; i < 3; i++)
        printf("%d %d\n", newset2[i].a, newset2[i].b);
}

void try_vector() {
    vector<int> a(5);
    a[0] = 1;
    a[1] = 2;
    printf("%d\n", a.size());

    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.pop_back();
    printf("%d\n", b.size());
    b.erase(b.begin());
    printf("%d\n", b.size());
}

int main() {
    try_vector();    
    return 0;
}