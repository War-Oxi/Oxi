#include "Monster.h"

<<<<<<< HEAD
int main(){
    Monster myMonster("KangKang", Position2D(0,0));
    myMonster.moveTo(Position2D(5, 9));
    std::cout << myMonster << std::endl;

    Monster myMonster2("Parsival", Position2D(0,0));

    return 0;
=======
using namespace std;

int main()
{
    Monster mon1("Sanson", Position2D(0, 0));
    cout << mon1 << endl;
//    while (1)
    {
        mon1.moveTo(Position2D(1, 1));
        cout << mon1 << endl;
    }
>>>>>>> 0d237e5f087aba07936aeae20b10fd0b7f9d7e06
}