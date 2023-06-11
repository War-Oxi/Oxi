#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(int a, int b){
  return a > b;
}
int main() {
//  cout << (int)'A';0
//  cout << (int)'Z';26

  int N;
  cin >> N;

  deque<pair<int, char>> Q;
  deque<pair<int, char>> Q2;
  deque<pair<int, char>> tmpQ;

  int alphabetCount[40];
  fill(alphabetCount, alphabetCount+40, 0);
  for(int i=0; i<N; i++){
    string command;
    char alphabet;
    cin >> command;

    if(command == "enqueue"){
      cin >> alphabet;
      Q.push_back({++alphabetCount[alphabet-'A'], alphabet});
      Q2 = Q;
      sort(Q2.begin(), Q2.end(), greater<>());

//      for(auto &ele: Q2){
//        cout << ele.first << " " << ele.second << endl;
//      }
    }
    if(command == "dequeue"){
     char popAlphabet = Q2.front().second; Q2.pop_front();
     while(Q.front().second != popAlphabet){
       auto tmpAlphabet = Q.front(); Q.pop_front();
       tmpQ.push_back(tmpAlphabet);
     }
     cout << Q.front().second << " ";
     Q.pop_front();
     while(!tmpQ.empty()){
       auto tmpAlphabet = tmpQ.back(); tmpQ.pop_back();
       Q.push_front(tmpAlphabet);
     }
    }
  }
  return 0;
}