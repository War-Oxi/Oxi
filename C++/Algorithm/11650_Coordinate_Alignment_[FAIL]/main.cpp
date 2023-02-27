#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//bool compareX(vector<int> &v1, vector<int> &v2){
//    return v1[0] < v2[0];
//}
//
//// X의 값이 같은 경우
//bool compareY(vector<int> &v1, vector<int> &v2){
//    if(v1[0] == v2[0] && v1[1] < v2[1])
//        return true;
//    else
//        return false;
//
//}

bool compareVec(vector<int> &v1, vector<int> &v2){
    if(v1[0] < v2[0]){
        return true;
    }
    else if(v1[0] == v2[0]){
        return v1[1] < v2[1];
    }
}

int main(){
    int N;
    cin >> N;
    vector <vector <int>> my_vec;
    vector <int> tmp_vec;

    for(int i=0; i<N; i++){
        int tmp[2];
        cin >> tmp[0] >> tmp[1];
        tmp_vec.push_back(tmp[0]);
        tmp_vec.push_back(tmp[1]);
        my_vec.push_back(tmp_vec);
        vector <int>().swap(tmp_vec);
    }

//    std::sort(my_vec.begin(), my_vec.end(), compareVec);
    std::sort(my_vec.begin(), my_vec.end());

    for(auto& ele: my_vec){
        cout << ele[0] << " " << ele[1] << "\n";
    }
//    cout << my_vec[0][0] << my_vec[0][1] << endl;
//    cout << my_vec[1][0] << my_vec[1][1] << endl;

    return 0;
}