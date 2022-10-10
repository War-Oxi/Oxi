#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void Get_Average_Value(const std::vector<int>& arr);
void Get_Middle_Value(const std::vector<int>& arr);
void Get_Most_Frequency_Value(const std::vector<int>& arr);
void Get_Range_Value(const std::vector<int>& arr);

int main() {
//    int avg_value(-1), middle_value(-1), most_frequency_value(-1), range_value(-1);
    int num_of_value(-1);
    cin >> num_of_value;

    std::vector<int> arr;
    for (int i=0; i<num_of_value; i++){
        int temp_num(-1);
        cin >> temp_num;
        if(abs(temp_num) > 4000)
            cout << "out of range value. program will be close" << endl;
        else
            arr.push_back(temp_num);
    }
    std::sort(arr.begin(), arr.end());

    Get_Average_Value(arr);
    Get_Middle_Value(arr);
    Get_Most_Frequency_Value(arr);
    Get_Range_Value(arr);

    return 0;
}

void Get_Average_Value(const std::vector<int>& arr){
    int sum(0);
    for(auto &num : arr)
        sum += num;
//    double avg(0);
    double avg = (double)sum / int(arr.size());
    cout << std::round(avg) << endl;
//    cout << sum / int(arr.size()) <<endl;
}

void Get_Middle_Value(const std::vector<int>& arr){
    cout << arr[arr.size()/2] << endl;
}

void Get_Most_Frequency_Value(const std::vector<int>& arr){
    int max_count(-1);
    bool flag = false;

    for(int i=0; i<arr.size(); i++){
        int temp_count = std::count(arr.begin(), arr.end(), arr[i]);
        if(temp_count > max_count){
            flag = false;
            max_count = temp_count;
        }
        else if (temp_count == max_count && !flag){
            flag = true;
            max_count = temp_count;
        }
    }
    cout << max_count << endl;
}

void Get_Range_Value(const std::vector<int>& arr){
    cout << arr.back() - arr.front() << endl;
//    cout << *arr.end() - *arr.begin() << endl;
}