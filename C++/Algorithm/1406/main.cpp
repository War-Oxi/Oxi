#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

#define endl "\n"
//const int MX = 1000005;
//int dat[MX], pre[MX], next[MX];
//int unused=1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  list<char> my_list;

  string string_in;
  cin >> string_in;

  for(auto & ele : string_in) my_list.push_back(ele);
  auto cursor = my_list.end();

  int num_of_command;
  cin >> num_of_command;

  while(num_of_command--){
    char command;
    cin >> command;

    if(command == 'L'){
      //커서를 왼쪽으로 한 칸 옮김
      if(cursor == my_list.begin())
        continue;
      cursor--;
    }
    else if(command == 'D'){
      //커서를 오른쪽으로 한 칸 옮김
      if(cursor == my_list.end())
        continue;
      cursor++;
    }
    else if(command == 'B'){
      //커서 왼쪽에 있는 문자 삭제
      if(cursor == my_list.begin())
        continue;
      cursor--;
      cursor = my_list.erase(cursor);
    }
    else if(command == 'P'){
      //문자를 입력받고 문자를 커서 왼쪽에 추가
      char char_in;
      cin >> char_in;
      my_list.insert(cursor, char_in);
    }
  }
  
  for(auto & ele : my_list)
    cout << ele;
  
  cout << endl;

  return 0;
}
