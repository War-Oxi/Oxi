//2839_설탕배달
#include <iostream>

using namespace std;

int main() {
    int bag_3kg(0), bag_5kg(0), sugar_weight(0);
    cin >> sugar_weight;
    bag_5kg = sugar_weight/5;
    while(true){
        if(bag_5kg < 1 && sugar_weight%3 != 0){
            cout << -1 << endl;
            return 0;
        }
        if((sugar_weight-(5*bag_5kg)) % 3 == 0){
            bag_3kg = (sugar_weight - (5*bag_5kg)) / 3;
            break;
        }
        bag_5kg--;
    }
    cout << bag_3kg + bag_5kg << endl;

    return 0;
}
