#include <iostream>
#include <stack>
#include <string>
#define endl "\n"

using namespace std;

int value(0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);

  stack<char> my_stack;

  for(auto ele : s){
    if(ele == '(' || ele == '['){
      my_stack.push(ele);
    }
    else if(ele == ')'){

    }
    else if(ele == ']'){

    }
  }


  return 0;
}
