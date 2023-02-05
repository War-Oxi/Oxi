// 3036_Ring
#include <iostream>
using namespace std;

int Calc_Greatest_Common_Factor(int num1, int num2);
void Ring_Rotation_Counter(int num);

int main() {
    int ring_num(0);
    cin >> ring_num;

    Ring_Rotation_Counter(ring_num);

    return 0;
}

int Calc_Greatest_Common_Factor(int num1, int num2){
    int a = num1 < num2 ? num1 : num2;
    while(a>0){
        if(num1 % a == 0 && num2 % a ==0){
            break;
        }
        a--;
    }
    if(a == 1)
        return 1;
    else
        return a;
}

void Ring_Rotation_Counter(int num){
    int Ring[num];

    for(int i=0; i<num; i++){
        cin >> Ring[i];
    }

    for(int i=1; i<num; i++){
        int greatest_common_factor(Calc_Greatest_Common_Factor(Ring[0], Ring[i]));
        cout << Ring[0]/greatest_common_factor << "/" << Ring[i]/greatest_common_factor<<endl;
    }
}
