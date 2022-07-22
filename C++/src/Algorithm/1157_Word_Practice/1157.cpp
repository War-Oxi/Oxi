
#include <iostream>

using namespace std;

int alphabet[26];
string input_string;

int main(){
    cin >> input_string;

    for(int i(0); i < input_string.length(); i++){
        input_string[i] = toupper(input_string[i]);
        alphabet[input_string[i]-'A']++;
    }
//    cout << input_string << endl;

    int max_frequency_alphabet(0),max_frequency_alphabet_index(0);
    for(int i(0); i < 26; i++){
        if(alphabet[i] > max_frequency_alphabet){
            max_frequency_alphabet = alphabet[i];
            max_frequency_alphabet_index = i;

        }
    }

    int count(0);
    for(int i(0); i < 26; i++){
        if(alphabet[i] == max_frequency_alphabet){
            count++;
        }
    }

    if(count > 1)
        cout << "?" << endl;
    else
        cout << (char)(max_frequency_alphabet_index + 65) << endl;


    return 0;
}