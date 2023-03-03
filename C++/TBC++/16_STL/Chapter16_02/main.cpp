#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main() {
    vector<int> container;
    for(int i=0; i<10; i++)
        container.push_back(i);

    vector<int>::const_iterator itr;
    itr = container.begin();
    while (itr != container.end())
    {
        cout << *itr << " ";

        ++itr;
    }
    cout << endl;

    return 0;
}