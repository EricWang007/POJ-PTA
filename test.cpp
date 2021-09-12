#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100];
char b[100];

int main(){
    int id;
    string name;
    scanf("%d", &id);
    // getchar();
    getline(cin, name); // 读入一行
    cout << id << name;

    return 0;
}