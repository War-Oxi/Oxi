//1021_회전하는 큐
#include <iostream>
using namespace std;
//예시 모두 통과, 제출 실패
int main() {
    int queue_size(0), extract_num(0);//큐사이즈, 추출할 숫자의 개수
    cin >> queue_size >> extract_num;
    int arr_extract_num[extract_num];//추출할 숫자의 배열
    int queue[queue_size];//큐
    for(int i=0; i<extract_num; i++){
        cin >> arr_extract_num[i];
    }
    for(int i=0; i<queue_size; i++){
        queue[i] = i+1;
    }

    int cur_location(0);//현재 인덱스
    int movement(0);//총 이동 횟수
    int tmp_movement[2];//더할 이동 횟수

    int extract_frequency(0);//현재 추출한 빈도
    while(extract_frequency < extract_num){
        tmp_movement[0]=0;
        tmp_movement[1]=0;
        if(queue[cur_location] == arr_extract_num[extract_frequency]){
            cur_location++;
            cur_location = arr_extract_num[extract_num];
            while(queue[cur_location] == -1){
                cur_location++;
                if(cur_location == queue_size)
                    cur_location = 0;
            }
        }
        else{
            int tmp_cur_location = cur_location;
            while(queue[tmp_cur_location] != arr_extract_num[extract_frequency]){
                tmp_cur_location++;
                if(queue[tmp_cur_location] == -1)
                    continue;
                tmp_movement[0]++;
                if(tmp_cur_location == queue_size){
                    tmp_cur_location = 0;
                    while(queue[tmp_cur_location] == -1){
                        tmp_cur_location++;
                    }
                }
            }
            tmp_cur_location = cur_location;
            while(queue[tmp_cur_location] != arr_extract_num[extract_frequency]){
                tmp_cur_location--;
                if(queue[tmp_cur_location] == -1)
                    continue;
                tmp_movement[1]++;
                if(tmp_cur_location < 0){
                    tmp_cur_location = queue_size-1;
                    while(queue[tmp_cur_location] == -1){
                        tmp_cur_location--;
                    }
                }
            }
        }
        queue[arr_extract_num[extract_frequency]-1] = -1;
        if(tmp_movement[0] <= tmp_movement[1])
            movement += tmp_movement[0];
        else
            movement += tmp_movement[1];
        cur_location = arr_extract_num[extract_frequency];
        if(cur_location == queue_size){
            cur_location = 0;
        }
        while(queue[cur_location] == -1){
            cur_location++;
        }
        extract_frequency++;
    }
    cout << movement << endl;
    return 0;
}
