#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> myVec(100);

void flatten(int numDumpRepeatsIn){
  while(numDumpRepeatsIn){
    *max_element(myVec.begin(), myVec.end()) -= 1;
    *min_element(myVec.begin(), myVec.end()) += 1;
    numDumpRepeatsIn--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int testCase=1; testCase <=10; testCase++){
    int numDumpRepeats;
    cin >> numDumpRepeats;

    for(int i=0; i<100; i++){
      cin >> myVec[i];
    }

    flatten(numDumpRepeats);
    cout << "#" << testCase << " " << *max_element(myVec.begin(), myVec.end()) - *min_element(myVec.begin(), myVec.end()) << endl;
  }

  return 0;
}
