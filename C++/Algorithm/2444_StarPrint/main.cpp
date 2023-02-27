#include <iostream>
using namespace std;

void printSpace(int n){
    for(int i=0; i<n; i++){
        cout << " ";
    }
}

void printStar(int n){
    for(int i=0; i<n; i++){
        cout << "*";
    }
    cout << "\n";
}

void printAll(){
    int N;
    cin >> N;

    int count(1);
    for(int i=N-1; i>=0; i--){
        printSpace(i);
        for(int j=0; j<count; j++){
            cout << "*";
        }
        cout << "\n";
        if(count >= N*2-1)
            count -=2;
        else
            count +=2;
    }

    for(int i=1; i<=N-1; i++){
        printSpace(i);
        for(int j=0; j<count; j++){
            cout << "*";
        }
        cout << "\n";
        count-=2;
    }
}

int main() {
    printAll();
    return 0;
}
