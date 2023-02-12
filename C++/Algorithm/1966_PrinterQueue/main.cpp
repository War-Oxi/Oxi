#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void printQueue(){
    queue<pair<int, int>> queue;
    priority_queue<int> priority_queue;
    int queue_size;
    cin >> queue_size;

    int print_document_index;
    cin >> print_document_index;

    for(int i=0; i<queue_size; i++){
        int tmp;
        cin >> tmp;
        queue.push({i, tmp}); //i => document num index, tmp => priority
        priority_queue.push(tmp);
    }

    int count(0);

    while(true) {
        int index = queue.front().first;
        int priority = queue.front().second;
        if(priority_queue.top() == priority){
            queue.pop();
            priority_queue.pop();
            count++;
            if(index == print_document_index) {
                break;
            }
        }
        else{
            queue.pop();
            queue.push({index, priority});
        }
        /**1
         * 1. queue의 front의 중요도가 priority와 크거나 같은지 확인
         * 2. 만약 같다면 pop 후 count++
         * 3. 만약 다르다면 pop 후 그대로 push
         */
    }
    cout << count << "\n";
}


void printQueue2(){
    queue<pair<int, int>> queue;
    vector <int> priority_vec;
    int queue_size;
    cin >> queue_size;
    int print_document_index;
    cin >> print_document_index;

    for(int i=0; i<queue_size; i++){
        int tmp;
        cin >> tmp;
        queue.push({i, tmp}); //i => document num index, tmp => priority
        priority_vec.push_back(tmp);
    }
    std::sort(priority_vec.begin(), priority_vec.end());
//    for (auto & ele: priority_vec){
//        cout << ele << " ";
//    }
//    cout << endl << endl;

    int count(0);

    while(true) {
        int index = queue.front().first;
        int priority = queue.front().second;
        if(priority_vec.back() == priority){
            queue.pop();
            priority_vec.pop_back();
            count++;
            if(index == print_document_index) {
                break;
            }
        }
        else{
            queue.pop();
            queue.push({index, priority});
        }
        /**1
         * 1. queue의 front의 중요도가 priority와 크거나 같은지 확인
         * 2. 만약 같다면 pop 후 count++
         * 3. 만약 다르다면 pop 후 그대로 push
         */
    }
    cout << count << "\n";
}

int main() {
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        printQueue2();
    }

    return 0;
}
