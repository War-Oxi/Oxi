#include <iostream>
#include <algorithm>

using namespace std;

void extractNum(int &cursor);
void moveLeft(int &cursor);
void moveRight(int &cursor);
int find(int cursor, int find_idx);

int queue[52];
int min_idx(1), max_idx;
int counter(0);


int main(){
  int num_extract; // N, M
  cin >> max_idx >> num_extract; // N, M

  for(int i=0; i <= max_idx; i++) // initialize queue
    queue[i] = i;

  int cur(1);

  int extreact_num_arr[num_extract];
  for(int i=0; i<num_extract; i++){
    cin >> extreact_num_arr[i];
  }

  for(auto &ele : extreact_num_arr){
    int value = find(cur, ele);

    if(value < 0) {
      for(int i=1; i<=abs(value); i++){
        moveLeft(cur);
      }
      extractNum(cur);
    }
    else if(value > 0) {
      for(int i=1; i<=value; i++){
        moveRight(cur);
      }
      extractNum(cur);
    }
    else
      extractNum(cur);
  }

  cout << counter;
}

void extractNum(int &cursor){
  for(int i=cursor; i < max_idx; i++){
    queue[i] = queue[i+1];
  }
  max_idx--;
  if(cursor > max_idx) cursor = min_idx;
}

void moveLeft(int &cursor) {
  cursor--;
  if(cursor < min_idx) cursor = max_idx;
  counter++;
}

void moveRight(int &cursor) {
  cursor++;
  if(cursor > max_idx) cursor = min_idx;
  counter++;
}

int find(int cursor, int find_idx){
  int left_move_num(0), right_move_num(0);
  int tmp_cur;

  tmp_cur = cursor;
  while(queue[tmp_cur] != find_idx) { // 왼쪽 이동 횟수 구하기
    tmp_cur--;
    left_move_num++;
    if(tmp_cur < min_idx) tmp_cur = max_idx;
  }

  tmp_cur = cursor;
  while(queue[tmp_cur] != find_idx){ // 오른쪽 이동 횟수 구하기
    tmp_cur++;
    right_move_num++;
    if(tmp_cur > max_idx) tmp_cur = min_idx;
  }

  if(left_move_num <= right_move_num)
    return -left_move_num;
  else // (left_move_num > right_move_num)
    return right_move_num;
}