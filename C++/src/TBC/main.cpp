#include "Monster.h"

int main(){
    Monster myMonster("KangKang", Position2D(0,0));
    myMonster.moveTo(Position2D(5, 9));
    std::cout << myMonster << std::endl;

    Monster myMonster2("Parsival", Position2D(0,0));

    return 0;
}