#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void Get_Average_Value(int arr_size, int sum);
void Get_Middle_Value(const std::vector<int>& arr);
void Get_Most_Frequency_Value(int arr2[]);
void Get_Range_Value(const std::vector<int>& arr);

int main() {
    int num_of_value(-1), sum(0);
    int arr2[8001] = {0,}; // 최빈값에 사용되는 배열
    cin >> num_of_value;
    if (!(1 <= num_of_value && num_of_value <= 500000)) {
        cout << "잘못된 값 입력" << endl;
        return 0;
    }
    std::vector<int> arr;
    for (int i=0; i<num_of_value; i++){
        int temp_num(-1);
        cin >> temp_num;
        if(abs(temp_num) > 4000)
            cout << "out of range value. program will be close" << endl;
        else {
            sum += temp_num;
            arr2[temp_num+4000]++;
            arr.push_back(temp_num);
        }
    }
    std::sort(arr.begin(), arr.end());

    Get_Average_Value(num_of_value, sum);
    Get_Middle_Value(arr);
    Get_Most_Frequency_Value(arr2);
    Get_Range_Value(arr);

    return 0;
}

void Get_Average_Value(int arr_size, int sum){
    double avg = (double)sum / arr_size;
    cout << int(std::round(avg)) << endl;
}

void Get_Middle_Value(const std::vector<int>& arr){
    cout << arr[arr.size()/2] << endl;
}

void Get_Most_Frequency_Value(int arr2[]){
    bool flag;
    int max_count(-1), most_frequency_value(0);
    for(int i=0; i<8001; i++){
        if(arr2[i]==0)
            continue;
        if(arr2[i] > max_count){
            flag = false;
            max_count = arr2[i];
            most_frequency_value = i-4000;
        }
        else if (arr2[i] == max_count && !flag){
            flag = true;
            max_count = arr2[i];
            most_frequency_value = i-4000;
        }
    }
    cout << most_frequency_value << endl;
}

void Get_Range_Value(const std::vector<int>& arr){
    cout << arr.back() - arr.front() << endl;
}