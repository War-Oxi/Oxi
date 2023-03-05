#include <iostream>
#include <tuple>

using namespace std;

//tuple<int, int> my_func()
//{
//    return tuple<int, int>(123, 456);
//}

//auto my_func()
//{
//    return tuple<int, int, int>(123, 456, 789);
//}

auto my_func()
{
    return tuple(123, 456, 789, 10); //c++17에서는 <int, int, int>를 붙이지 않아도 가능
}

int main() {
    auto [a, b, c, d] = my_func();

    cout << a << " " << b << " " << c << " " << d << " " << endl;
//    auto result = my_func();
//    cout << get<0>(result) << " " << get<1>(result) << "" << get<2>(result) << endl;

    return 0;
}