#include <iostream>
#include <limits>
int main() {
    using namespace std;

    char c1(65);

    cout << sizeof(unsigned char) << endl;
    cout << (int)std::numeric_limits<unsigned char>::max() << endl;
    cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;

    return 0;
}