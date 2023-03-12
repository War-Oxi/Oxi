#include <iostream>
#include <string>

using namespace std;

std::string phrase(std::string str_in){
    string tmp;
    tmp.push_back(str_in[0]);
    for(int i = 1; i < str_in.size(); i++){
        if(tmp == str_in.substr(i,i))
            break;
        else
            tmp.push_back(str_in[i]);
    }

    return tmp;
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; ++i){
        string test_str;
        cin >> test_str;

        cout << "#" << i << " " << phrase(test_str).size() << endl;
    }

    return 0;
}

/**
 * 1. 입력된 string의 문자 n개 저장. (1씩 증가. 최대
 * 2. 다음
 *
*/

