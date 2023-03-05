#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> my_queue;
//    my_queue;

    for (int i=1; i<=N; i++){
        my_queue.push(i);
//        cout << my_queue.size() << endl;
    }

    while(my_queue.size() != 1){
        my_queue.pop();
        my_queue.push(my_queue.front());
        my_queue.pop();

    }

    cout << my_queue.back() << endl;

    return 0;
}
