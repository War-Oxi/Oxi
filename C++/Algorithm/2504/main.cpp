//#include <iostream>
//#include <stack>
//#include <string>
#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> my_stack;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int sum(0);
  int tmp(1);
  bool flag(true);
  cin >> s;

  char tmp_char('A');

  for(auto ele : s){
    if(ele == '('){
      my_stack.push(ele);
      tmp *= 2;
    }
    else if(ele == '['){
      my_stack.push(ele);
      tmp *= 3;
    }
    else if(ele == ')'){
      if (my_stack.empty() || my_stack.top() != '('){
        flag = false;
        break;
      }
      if (tmp_char == '(') {
        sum += tmp;
      }
      tmp /= 2;
      my_stack.pop();
    }
    else if(ele == ']'){
      if (my_stack.empty() || my_stack.top() != '['){
        flag = false;
        break;
      }
      if (tmp_char == '[') {
        sum += tmp;
      }
      tmp /= 3;
      my_stack.pop();
    }
    tmp_char = ele;
  }

  if(flag && my_stack.empty())
    cout << sum;
  else
    cout << 0;

  return 0;
}
