#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string input,output;
    cin >> input;
    int freq[10] = {0};
    int c = 0;
    for (int i = input.length()-1; i >= 0 ; i--) {
        int x = input[i] - '0';
        freq[x]++;
        x = x*2+c;
        output += x%10 + '0';
        freq[x%10]--;
        c = x/10;
    }
    if (c) {
        output += c%10 + '0';
        freq[c%10]--;
    }
    reverse(output.begin(), output.end());
    bool flag = true;
    for (int i = 0; i <= 9; i++){
        if (freq[i] != 0) {
            printf("No\n");
            flag = false;
            break;
        }
    }
    if (flag) printf("Yes\n");
    cout << output;

    return 0;
}