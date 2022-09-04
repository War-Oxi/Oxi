//10828 스택
#include <iostream>
using namespace std;

struct Stack{
    int stack[10000];
    int stack_pointer;
    void Push(int num){
        stack[stack_pointer] = num;
        stack_pointer++;
    }
    void Pop(){
//        stack[stack_pointer] = -1; //하지 않아도 괜찮다. 확실하게 하기 위함
        if(stack_pointer == 0){
            cout << -1 << endl;
        }
        else{
            cout<<stack[stack_pointer-1]<<endl;
            stack_pointer--;
        }
    }
    void Size() const{
        cout << stack_pointer << endl;
    }
    void Empty() const{
        if(stack_pointer == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    void Top() const{
        if(stack_pointer == 0)
            cout << -1 << endl;
        else
            cout << stack[stack_pointer-1] << endl;
    }
};

int main() {
    Stack stack{0};
    int num_of_commands(0);
    cin >> num_of_commands;
    cin.clear();
    while(num_of_commands > 0){
        std::string command;
        cin >> command;
        if(command == "push"){
            int num(0);
            cin >> num;
            stack.Push(num);
        }
        else if(command == "pop"){
            stack.Pop();
        }
        else if(command == "size"){
            stack.Size();
        }
        else if(command == "empty"){
            stack.Empty();
        }
        else if(command == "top"){
            stack.Top();
        }
        else{
            cout << "Invalid input" << endl;
            break;
        }
        num_of_commands--;
    }

    return 0;
}
