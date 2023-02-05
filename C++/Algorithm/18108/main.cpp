#include <iostream>

int main()
{
    int a=0, b=0, c=0;

    std::cin>>a>>b>>c;

    if(b+c >=60){
        a += (b+c)/60;
        b = (b+c)%60;
    }
    else{
        b+=c;
    }
    a = a%24;
    std::cout<<a<<" "<<b<<std::endl;

    return 0;
}