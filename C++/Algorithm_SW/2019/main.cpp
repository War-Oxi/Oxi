#include <iostream>

int main() {
    int result(1), N;
    std::cin >> N;

    for (int i=0; i<N; i++){
        std::cout << result << " ";
        result *= 2;
    }
    std::cout << result;

    return 0;
}
