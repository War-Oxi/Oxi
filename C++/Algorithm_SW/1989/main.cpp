#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(const std::string &str_input){
    int str_size = str_input.length();
//    bool checker(true);
    for(int i=0; i<str_size/2; i++){
        if(str_input[i] != str_input[str_size-(i+1)])
            return false;
    }
    return true;
}

int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; ++i){
        std::string str_in;
        cin >> str_in;
        cout << "#" << i << " " << checkPalindrome(str_in) << endl;
    }

    return 0;
}
