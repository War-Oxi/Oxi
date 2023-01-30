#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    deque<int> deque;

    int N; // 입력받을 횟수
    cin >> N;

    for(int i=0; i<N; i++) {
        string option;
        cin >> option;
        if (option == "push_back") {
            int value;
            cin >> value;
            deque.push_back(value);
        } else if (option == "push_front") {
            int value;
            cin >> value;
            deque.push_front(value);
        } else if (option == "pop_front") {
            if(!deque.empty()){
                cout << deque.front() << endl;
                deque.pop_front();
            }
            else
                cout << "-1" << endl;
        } else if (option == "pop_back") {
            if(!deque.empty()){
                cout << deque.back() << endl;
                deque.pop_back();
            }
            else
                cout << "-1" << endl;
        } else if (option == "empty") {
            if(deque.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        } else if (option == "size") {
            cout << deque.size() << endl;
        } else if (option == "front") {
            if(!deque.empty())
                cout << deque.front() << endl;
            else
                cout << "-1" << endl;
        } else if (option == "back") {
            if(!deque.empty())
                cout << deque.back() << endl;
            else
                cout << "-1" << endl;
        }
    }
    return 0;
}



//#include <iostream>
//#include <string>
//#define INT_MAX 10000
//using namespace std;
//
//class Deque{
//private:
//    int frontIndex;
//    int backIndex;
//    int data[INT_MAX]{};
//public:
//    Deque()
//        :frontIndex(0), backIndex(0)
//    {}
//    void push_front(int num_in){
//        data[frontIndex] = num_in;
//        frontIndex = (frontIndex - 1 + INT_MAX)%INT_MAX;
//    }
//    void push_back(int num_in){
//        backIndex = (backIndex + 1)%INT_MAX;
//        data[backIndex] = num_in;
//    }
//
//    void pop_front(){ //
//        if(!empty()){
//            frontIndex = (frontIndex + 1)%INT_MAX;
//            std::cout << data[frontIndex] << endl;
//        }
//        else{
//            cout << "-1" << "\n";
//        }
//    }
//    void pop_back(){ //
//        if(!empty()){
//            std::cout << data[backIndex] << endl;
//            backIndex = (backIndex - 1 + INT_MAX)%INT_MAX;
//        }
//        else{
//            cout << "-1" << "\n";
//        }
//    }
//    bool empty() const{
//        if(frontIndex == backIndex){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    void size() const{
//        if(empty()){
//            cout << "0" << "\n";
//        }
//        else{
//            if(frontIndex <= backIndex){
//                cout << backIndex << endl;
//            }
//            else{
//                cout << 10000 + backIndex - frontIndex << "\n";
//            }
//        }
//    }
//    void front() const{
//        if(empty()){
//            cout << "-1" << endl;
//        }
//        else
//            cout << data[(frontIndex + 1)%INT_MAX] << "\n";
//    }
//    void back() const{
//        if(empty()){
//            cout << "-1" << endl;
//        }
//        else
//            cout << data[backIndex] << "\n";
//    }
////    push_front X: 정수 X를 덱의 앞에 넣는다.
////    push_back X: 정수 X를 덱의 뒤에 넣는다.
////    pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
////    pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
////    empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
////    size: 덱에 들어있는 정수의 개수를 출력한다.
////    front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
////    back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//};
//
//void input(Deque &deque){
//    int num_repeat;
//    cin >> num_repeat;
//
////    string input_str[num];
//    for(int i=0; i<num_repeat; i++){
//        string option;
//        cin >> option;
//        if(option == "push_back"){
//            int value;
//            cin >> value;
//            deque.push_back(value);
//        }
//        else if(option == "push_front"){
//            int value;
//            cin >> value;
//            deque.push_front(value);
//        }
//        else if(option == "pop_front"){
//            deque.pop_front();
//        }
//        else if(option == "pop_back"){
//            deque.pop_back();
//        }
//        else if(option == "empty"){
//            cout << deque.empty() << endl;
//        }
//        else if(option == "size"){
//            deque.size();
//        }
//        else if(option == "front"){
//            deque.front();
//        }
//        else if(option == "back"){
//            deque.back();
//        }
//    }
//}
//
//int main(){
//    Deque deque;
//
//    input(deque);
////    deque.pop_front();
////    deque.pop_back();
////    deque.front();
////    deque.back();
////    cout << "\n\n";
////    deque.front();
////    deque.size();
//
//    return 0;
//}
