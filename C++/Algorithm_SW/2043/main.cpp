#include <iostream>
using namespace std;

int main() {
    int password, key;
    cin >> password >> key;

    int count=1;
    while(key != password){
        count++;
        key++;

        if(key > 999) break;
    }

    cout << count << endl;
    return 0;
}
