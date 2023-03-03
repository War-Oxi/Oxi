#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void goodbye(const string & s){

}

class Object
{
public:
    void hello(const string & s)
    {
        cout << "Hello" << s << endl;
    }
};

int main() {

    auto func = [](const int & i) -> void {cout << "Hello World!" << endl; };

    func(123);

    [](const int & i) -> void {cout << "Hello World!" << endl; } (1234);
    {
        string name = "JackJack";
        [&]() {std::cout << name << endl;} ();
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    auto func2 = [](int val) {cout << val << endl; };
    for_each(v.begin(), v.end(), func2);
//    for_each(v.begin(), v.end(), [](int val) {cout << val << endl;}); //이렇게 쓰는게 더 나음

    cout << []() -> int {return 1;}() << endl;

    std::function<void(int)> func3 = func2; //return type이 void일 경우 return type을 적지 않아도 된다.
    func3(123);

//    std::function<void()>func4 = [func3] { return func3(456); };
    std::function<void()>func4 = std::bind(func3, 456);
    func4();

    {
        Object instance;
        auto f = [ObjectPtr = &instance](auto && PH1)
                { ObjectPtr->hello(std::forward<decltype(PH1)>(PH1)); };
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

        f(string("World"));

        auto f2 = std::bind(&goodbye, std::placeholders::_1);

        f2(string("World"));
    }

    return 0;
}
