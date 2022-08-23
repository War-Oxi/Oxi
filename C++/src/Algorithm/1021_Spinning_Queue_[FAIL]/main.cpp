//1021_회전하는 큐
#include <iostream>
using namespace std;
//마지막 출력에서 실패함. 이유 모름
int main() {
    int queue_size(0), extract_num(0);
    cin >> queue_size >> extract_num;
    int arr_extract_num[extract_num];
    int queue[queue_size];
    for(int i=0; i<extract_num; i++){
        cin >> arr_extract_num[i];
    }
    for(int i=0; i<queue_size; i++){
        queue[i] = i+1;
    }

    int cur_location(0);
    int movement(0);
    int tmp_movement[2];

    int extract_frequency(0);
    while(extract_frequency < extract_num){
        if(queue[cur_location] == arr_extract_num[extract_num]){
            queue[cur_location] = -1;
            cur_location = arr_extract_num[extract_num];
            while(queue[cur_location+1] == -1){
                cur_location++;
                if(cur_location == queue_size)
                    cur_location = 0;
            }
        }
        else{
            tmp_movement[0]=0;
            tmp_movement[1]=0;
            int tmp_cur_location = cur_location;
            while(queue[tmp_cur_location] != arr_extract_num[extract_frequency]){
                tmp_cur_location++;
                if(queue[tmp_cur_location] == -1)
                    continue;
                if(tmp_cur_location == queue_size){
                    tmp_cur_location = 0;
                    while(queue[tmp_cur_location] == -1){
                        tmp_cur_location++;
                    }
                }
                tmp_movement[0]++;
            }
            tmp_cur_location = cur_location;
            while(queue[tmp_cur_location] != arr_extract_num[extract_frequency]){
                tmp_cur_location--;
                if(queue[tmp_cur_location] == -1)
                    continue;
                if(tmp_cur_location < 0){
                    tmp_cur_location = queue_size-1;
                    while(queue[tmp_cur_location] == -1){
                        tmp_cur_location--;
                    }
                }
                tmp_movement[1]++;
            }
        }
        if(tmp_movement[0] <= tmp_movement[1])
            movement += tmp_movement[0];
        else
            movement += tmp_movement[1];
        cur_location = arr_extract_num[extract_frequency];
        if(cur_location == queue_size){
            cur_location = 0;
            while(queue[cur_location] == -1){
                cur_location++;
            }
        }
        queue[arr_extract_num[extract_frequency]-1] = -1;
        extract_frequency++;
    }
    cout << movement << endl;
    return 0;
}
