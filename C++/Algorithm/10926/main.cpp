#include <iostream>
#include <cstring>

int main() {
    char input_name[51];

    std::cin>>input_name;

    std::strcat(input_name, "??!");

    std::cout<<input_name<<std::endl;

    return 0;
}
