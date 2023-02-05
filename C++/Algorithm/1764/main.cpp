//1764 듣보잡
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void inputPerson(int num, vector<string> &vec){
    for (int i=0; i<num; i++){
        string tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
}

int main() {
    int nNotHeardPerson(0), nNotSeenPerson(0);
    cin >> nNotHeardPerson >> nNotSeenPerson;

    std::vector<string> vecNotHeardPerson, vecNotHeardNotSeenPerson;

    inputPerson(nNotHeardPerson, vecNotHeardPerson);

    sort(vecNotHeardPerson.begin(), vecNotHeardPerson.end());
    for(int i = 0; i<nNotSeenPerson; i++){
        string tmp;
        cin >> tmp;
        if (binary_search(vecNotHeardPerson.begin(), vecNotHeardPerson.end(), tmp)){
            vecNotHeardNotSeenPerson.push_back(tmp);
        }
    }

    sort(vecNotHeardNotSeenPerson.begin(), vecNotHeardNotSeenPerson.end());
    cout << vecNotHeardNotSeenPerson.size() << endl;
    for(auto &str: vecNotHeardNotSeenPerson){
        cout << str << endl;
    }

    return 0;
}
