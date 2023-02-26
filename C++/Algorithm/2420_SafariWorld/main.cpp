#include <iostream>

int main() {
    long long N, M;
    std::cin >> N >> M;
    long long result = N-M;

    if(result < 0)
        std::cout << -result << std::endl;
    else
        std::cout << result << std::endl;
    return 0;
}
