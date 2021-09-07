#include <iostream>
#include <set>
#include <stack>

using namespace std;

char range[] = {'p', 'q', 'r', 's', 't'};
set<char> symbol(range, range+5);

// code: pqrst
bool to_val(char ch, int code) {
  bool val;
  switch (ch) {
    case 'p':
      val = (code & 1) ? true : false;
      break;
    case 'q':
      val = (code & 2) ? true : false;
      break;
    case 'r':
      val = (code & 4) ? true : false;
      break;
    case 's':
      val = (code & 8) ? true : false;
      break;
    case 't':
      val = (code & 16) ? true : false;
      break;
    default:
      break;
  }
  return val;
}

bool judge(string s, int code) {
  stack<bool> Stack;
  int len = s.length();
  for (int i = len - 1; i >= 0; i--) {
    char ch = s[i];
    if (symbol.find(ch) != symbol.end()) {
      bool val = to_val(ch, code);
      Stack.push(val);
    } else {
      if ('N' == ch) {
        bool val = Stack.top();
        Stack.pop();
        Stack.push(!val);
      } else {
        bool val1 = Stack.top();
        Stack.pop();
        bool val2 = Stack.top();
        Stack.pop();
        switch (ch) {
          case 'K':
            Stack.push(val1 & val2);
            break;
          case 'A':
            Stack.push(val1 | val2);
            break;
          case 'C':
            Stack.push(!(val1 && !val2));
            break;
          case 'E':
            Stack.push(val1 == val2);
            break;
          default:
            break;
        }
      }
    }
  }
  return Stack.top();
}

int main() {
  string s;
  while (cin >> s) {
    if ("0" == s) break;
		int i;
    for (i = 0; i < 32; i++) {
      if (!judge(s, i)) break;
    }
    if (i < 32)
      cout << "not" << endl;
    else
      cout << "tautology" << endl;
  }
  return 0;
}