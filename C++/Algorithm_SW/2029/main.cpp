#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        cout << "#" << i+1 << " " << tmp1/tmp2 << " " << tmp1%tmp2 << endl;
    }
    return 0;
}
