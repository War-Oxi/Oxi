#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int min, max;
    std::cin >> min >> max;
    std::vector <bool> vec_num(max+1, true);
    vec_num[0] = false;
    vec_num[1] = false;
    for(int i = 2; i<=max; i++){
//        if(!(vec_num[i])){
//            continue;
//        }
        for(int j = i*2; j<=max; j += i ){
            vec_num[j] = false;
        }
    }

    int count(0);
    for(int i = min; i<=max; i++){
        if(vec_num[i]){
            std::cout << i << "\n";
//            count++;
        }
    }
//    std::cout << count << std::endl;

    return 0;
}
