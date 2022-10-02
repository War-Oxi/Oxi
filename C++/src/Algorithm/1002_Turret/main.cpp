#include <iostream>
#include <cmath>
using namespace std;

void Finding_Marin_Locatoin(){
    int pos1[3], pos2[3];
    cin >> pos1[0] >> pos1[1] >> pos1[2] >> pos2[0] >> pos2[1] >> pos2[2]; //pos[0] = x좌표 pos[1] = y좌표 pos[2] = 반지름

    double distance_of_pos = sqrt(pow((pos1[0]-pos2[0]),2) + pow((pos1[1]-pos2[1]),2));
//    int diff_radius = pos1[2] > pos2[2] ? pos1[2] - pos2[2] : pos2[2] - pos1[2];
    int radius_minus = abs(pos1[2] - pos2[2]);
    int radius_plus = pos1[2] + pos2[2];

    if(radius_minus == 0 && distance_of_pos == 0){
        cout << -1 << endl;
    }
    else if (radius_plus == distance_of_pos || radius_minus == distance_of_pos){
        cout << 1 << endl;
    }
    else if (radius_minus < distance_of_pos && distance_of_pos < radius_plus){
        cout << 2 << endl;
    }
    else{
        cout << 0 << endl;
    }
}

int main() {
    int Test_Num(0);
    cin >> Test_Num;
    for(int i=0; i<Test_Num; i++){
        Finding_Marin_Locatoin();
    }

    return 0;
}
