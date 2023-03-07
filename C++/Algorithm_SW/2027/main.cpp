#include <iostream>
#include <string>

using namespace std;

int main() {
    int T=5;
    string my_str = "+++++";
    for(int i=0; i<T; i++){
        string tmp_str = my_str;
        tmp_str[i] = '#';
        cout << tmp_str << endl;
    }

    return 0;
}
