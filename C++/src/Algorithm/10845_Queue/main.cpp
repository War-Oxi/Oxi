#include <iostream>
#include <string>
using namespace std;

int queue[10000], rear = 0, front = 0;

void push();
void pop();
void size();
void empty();
void printFront();
void printBack();

int main() {
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        std::string str_in;
        cin >> str_in;
        if(str_in == "push"){
            push();
        }
        else if(str_in == "pop"){
            pop();
        }
        else if(str_in == "size"){
            size();
        }
        else if(str_in == "empty"){
            empty();
        }
        else if(str_in == "front"){
            printFront();
        }
        else if(str_in == "back"){
            printBack();
        }
    }


    return 0;
}

void push(){
    int x;
    cin >> x;
    queue[rear++]=x;
}

void pop(){
    if(rear==front){
        cout << "-1" << endl;
    }
    else
        cout << queue[front++] << endl;
}

void size(){
    cout << rear-front << endl;
}

void empty(){
    if(rear==front){
        cout << "1" << endl;
    }
    else
        cout << "0" << endl;
}

void printFront(){
    if(rear==front){
        cout << "-1" << endl;
    }
    else{
        cout << queue[front] << endl;
    }
}

void printBack(){
    if(rear==front){
        cout << "-1" << endl;
    }
    else{
        cout << queue[rear-1] << endl;
    }
}