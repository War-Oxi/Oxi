#include <iostream>
using namespace std;

bool divisionThree(int num_in){
    if (num_in % 3 == 0 && num_in != 3)
        return true;
    else
        return false;
}

bool divisionTwo(int num_in){
    if (num_in % 2 == 0 && num_in != 3)
        return true;
    else
        return false;
}

void makeOne(int num_in){
    int count(0);
    while(num_in != 1){
        if (divisionThree(num_in))
            num_in /= 3;
        if (divisionThree(num_in - 1))
            num_in -=1;
        else if (divisionTwo(num_in))
            num_in /= 2;
        else
            num_in -= 1;
        count++;
    }
    cout << count << endl;
}

int main() {
    makeOne(2);
    return 0;
}
