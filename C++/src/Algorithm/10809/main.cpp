#include <iostream>
using namespace std;

int main()
{
    int i=0, j;
    string input_word;
    string string_s = "abcdefghijklmnopqrstuvwxyz";

    cin>>input_word;

    for(i=0; i < string_s.length(); i++)
    {
        for(j=0; j < input_word.length(); j++)
        {
            if(input_word[j] == string_s[i])
            {
                cout << j << ' ';
                break;
            }
        }
        if(input_word[j] != string_s[i])
        {
            cout << -1 << ' ';
        }
    }
    return 0;
}

//1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1