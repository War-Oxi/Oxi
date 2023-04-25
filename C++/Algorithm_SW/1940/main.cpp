#include <iostream>
#include <vector>
using namespace std;

int getDistance(int num_of_command);

int main() {
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        int N, distance;
        cin >> N;
        distance = getDistance(N);

        cout << "#" << test_case << " " << distance << endl;

    }


    return 0;
}

int getDistance(int num_of_command){
    int speed(0), acceleration(0), distance(0), command;
    for(int i=0; i<num_of_command; i++){
        cin >> command;

        if(command == 0){ //현재 속도 유지
            distance += speed;
        }
        else if(command == 1){ //가속
            cin >> acceleration;
            speed += acceleration;
            distance += speed;
        }
        else if(command == 2){ //감속
            cin >> acceleration;
            speed -= acceleration;
            if(speed < 0) speed = 0;
            distance += speed;
        }
        else{
            cout << error_code() << endl;
        }
    }
    return distance;
}