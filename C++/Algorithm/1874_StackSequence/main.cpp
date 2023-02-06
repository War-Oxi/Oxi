#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> stack1;
    vector<char> result;

    int cnt = 1;
    int n;
    cin >> n;

    for (int i=0; i < n; i++){
        int x;
        cin >> x;

        while ( cnt <= x ){
            stack1.push(cnt++);
            result.push_back('+');
        }

        if(stack1.top() == x) {
            stack1.pop();
            result.push_back('-');
        }
        else {
            cout << "NO" << "\n";
            return 0;
        }
    }

    for(auto & element : result) {
        cout << element << "\n";
    }
    return 0;
}
