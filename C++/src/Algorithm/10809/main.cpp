#include <iostream>
//#include <cstring>

using namespace std;

int main() {
    string input_word;
    string word = "abcdefghijklmnopqrstuvwxyz";
    int j=0;
    cin>>input_word;

    for (int i = 0; i<word.length(); i++)
    {
        cout<<i;
        for (j; j<input_word.length(); j++)
        {
            if(word[i] == input_word[j])
            {
                cout << j << ' ';
                break;
            }
        }
        if(word[i] != input_word[j])
        {
            cout << -1 << ' ';
        }
    }


    return 0;
}
//int main()
//{
//    int i,j;
//    string alphabet= "abcdefghijklmnopqrstuvwxyz";
//    string s;
//    cin >> s;
//    for(i=0; i < 26; i++)
//    {
//        for(j=0; j < s.length(); j++)
//        {
//            if(s[j] == alphabet[i])
//            {
//                cout << j << ' ';
//                break;
//            }
//        }
//        if(s[j] != alphabet[i])
//            cout << -1 << ' ';
//    }
//}