#include <iostream>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<4; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if(tmp1 > tmp2)
            cout << "#" << i << " >" << endl;
        else if (tmp1 < tmp2)
            cout << "#" << i << " <" << endl;
        else
            cout << "#" << i << " =" << endl;
    }

    return 0;
}
