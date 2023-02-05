//4949_균형잡힌 세상
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    while(true){
        string input;
        getline(cin, input);

        if(input == "."){
            break;
        }

        vector<char> vec;
        bool flag = true;
        for (auto &element: input){
            if(element == '(')
                vec.push_back(element);
            else if(element == '[')
                vec.push_back(element);
            else if(element == ')') {
                if (!vec.empty() && vec.back() == '(')
                    vec.pop_back();
                else {
                    flag = false;
                    break;
                }
            }
            else if(element == ']'){
                if (!vec.empty() && vec.back() == '[')
                    vec.pop_back();
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag && vec.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}

