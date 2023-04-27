#include <iostream>
#include <stack>
#include <string>
#define endl "\n"

using namespace std;

unsigned long long wood_num(0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str_in;
  getline(cin, str_in);

  stack<char> my_stack;

  bool flag=false;
  for(char ele : str_in){
    if(ele == '('){
      my_stack.push('(');
      flag = false;
    }
    else{
      my_stack.pop();
      if(!flag){
        wood_num += my_stack.size();
        flag = true;
      }
      else{
        wood_num++;
      }
    }
  }

  cout << wood_num << endl;

  return 0;
}
