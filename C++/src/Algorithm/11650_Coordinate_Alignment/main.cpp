#include <iostream>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

using namespace std;

struct Coordinate{
    int x, y;
};

Coordinate SetCoordinate(int x, int y) {
    Coordinate temp = {x, y};
    return temp;
};

void ShowCoordinate(Coordinate name){
    cout << name.x << ", " << name.y << endl;
}

void BubbleSort(Coordinate list[], int n){
    int i, j;
    Coordinate temp{};
    for (i = n-1; i>0; i--){
        for(j = 0; j < i; j++){
            if(list[j].x > list[j+1].x){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    for (i = n-1; i>0; i--){
        for(j = 0; j < i; j++){
            if(list[j].x != list[j+1].x)
                continue;
            else if(list[j].y > list[j+1].y){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

int partition(Coordinate list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left].x; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

    /* low와 high가 교차할 때까지 반복(low<high) */
    do{
        /* list[low]가 피벗보다 작으면 계속 low를 증가 */
        do {
            low++; // low는 left+1 에서 시작
        } while (low<=right && list[low].x<pivot);

        /* list[high]가 피벗보다 크면 계속 high를 감소 */
        do {
            high--; //high는 right 에서 시작
        } while (high>=left && list[high].x>pivot);

        // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
        if(low<high){
            SWAP(list[low].x, list[high].x, temp);
        }
    } while (low<high);

    // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
    SWAP(list[left].x, list[high].x, temp);

    pivot = list[left].y; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

    /* low와 high가 교차할 때까지 반복(low<high) */
    do{
        /* list[low]가 피벗보다 작으면 계속 low를 증가 */
        do {
            low++; // low는 left+1 에서 시작
        } while (low<=right && list[low].y<pivot);

        /* list[high]가 피벗보다 크면 계속 high를 감소 */
        do {
            high--; //high는 right 에서 시작
        } while (high>=left && list[high].y>pivot);

        // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
        if(low<high && list[low].x == list[high].x){
            SWAP(list[low].y, list[high].y, temp);
        }
    } while (low<high);

    // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
    if(list[left].x == list[high].x)
        SWAP(list[left].y, list[high].y, temp);

    // 피벗의 위치인 high를 반환
    return high;
}

// 퀵 정렬
void quick_sort(Coordinate list[], int left, int right){

    /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
    if(left<right){
        // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
        int q = partition(list, left, right); // q: 피벗의 위치

        // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
        quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
        quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    }

}

int main() {
    int repeat_num(0);
    cin >> repeat_num;

    Coordinate coordinate[repeat_num];
    Coordinate coordinate_temp[repeat_num];
//    for (int i=0; i < 5; i++){
//        Coordinate[i] = SetCoordinate(1, 2);
//    }
    for (auto & i : coordinate){
        int x=0, y=0;
        cin >> x >> y;
        i = SetCoordinate(x, y);
    }

    for (auto & i : coordinate_temp){

    }

//    for (int i=0; i<5; i++){
//        ShowCoordinate(Coordinate[i]);
//    }
    quick_sort(coordinate, 0, repeat_num-1);
    for (auto i : coordinate){
        ShowCoordinate(i);
    }

    return 0;
}
