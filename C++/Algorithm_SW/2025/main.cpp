#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int sum(0);
    for (int i=1; i<=T; i++){
        sum += i;
    }
    std::cout << sum << std::endl;

    return 0;
}
