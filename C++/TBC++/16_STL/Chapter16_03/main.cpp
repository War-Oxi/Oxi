#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    vector<int> container;
    for (int i=0; i<10; ++i)
        container.push_back(i);

    auto itr = min_element(container.begin(), container.end());
    cout << *itr << endl;

    itr = max_element(container.begin(), container.end());
    cout << *itr << endl;

    itr = find(container.begin(), container.end(), 3);
    container.insert(itr, 128);

    sort(container.begin(), container.end());

    for (auto & e : container)  cout << e << " ";
    cout << endl;

    reverse(container.begin(), container.end());

    for (auto & e : container)  cout << e << " ";
    cout << endl;

    return 0;
}
