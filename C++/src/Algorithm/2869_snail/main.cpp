#include <iostream>

using namespace std;

int move_snail(int day_movement, int night_movement);

int main() {
    int day_movement(0), night_movement(0), height(0), day_count(0);
    cin >> day_movement >> night_movement >> height;
    int snail_movement = move_snail(day_movement, night_movement);
    int cur_height(0);
//    cout << (double)5/6 << endl;
    if( (height - day_movement) % snail_movement == 0 ){
        day_count = (height - day_movement) / snail_movement + 1;
    }
    else{
        day_count = (height - day_movement) / snail_movement + 2;
    }


    cout << day_count << endl;

    return 0;
}

int move_snail(int day_movement, int night_movement){
    return day_movement-night_movement;
}
