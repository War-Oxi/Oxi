#include <iostream>
using namespace std;

int main()
{
    int num_1, num_2, num_3;
    int reward=0;
    // Input value
    cin>>num_1>>num_2>>num_3;

    if (num_1 == num_2 && num_1 == num_3)
    {
        reward = num_1 * 1000 + 10000;
    }
    else if (num_1 == num_2 || num_1 == num_3 || num_2 == num_3)
    {
        if (num_1 == num_2 || num_1 == num_3)
        {
            reward = num_1 * 100 + 1000;
        }
        else if (num_2 == num_3)
        {
            reward = num_2 * 100 + 1000;
        }
    }
    else
    {
        if(num_1 > num_2 && num_1 >num_3)
        {
            reward = num_1 * 100;
        }
        else if (num_2 > num_1 && num_2 > num_3)
        {
            reward = num_2 * 100;
        }
        else
        {
            reward = num_3 * 100;
        }
    }

    cout<<reward<<endl;

    return 0;
}
