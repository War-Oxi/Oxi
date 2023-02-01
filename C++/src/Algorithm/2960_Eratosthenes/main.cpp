// 2960_에라스토테네스의 체
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> vector1;
    vector1.reserve(n);

    for(int i=2; i<=n; i++){
        vector1.push_back(i);
    }

    int count(0), num;


    for(int i=2; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            if(binary_search(vector1.begin(), vector1.end(), j)){
                count++;
                vector1.erase(remove(vector1.begin(), vector1.end(), j));
                if(count == k){
                    cout << j << endl;
                }
            }
        }
    }
//    for(int i=2; i<=n; i++){
//        int tmp_num=i;
//        while(tmp_num <= n){
//            for(auto &element: vector1){
//                if(element == tmp_num){
//                    remove(vector1.begin(),vector1.end(),element);
//                    cout << element << endl;
//                    count++;
////                    if(count == k)
////                        cout << element << endl;
//                }
//                tmp_num *= 2;
//            }
//        }
//    }
    return 0;
}
