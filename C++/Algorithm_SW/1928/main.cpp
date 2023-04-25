#include <iostream>
#include <map>
using namespace std;

void setEncodeTable(map<char, int> &table_in);

int main() {
    map<char, int> encoding_table;
    setEncodeTable(encoding_table);

    string str_in;

    return 0;
}

void setEncodeTable(map<char, int> &table_in){
    char character('A');
    int value(0);

    while(character != '/'){
        table_in.insert({character, value});

        if(character == 'Z')
            character = 'a';
        else if(character == 'z')
            character = '0';
        else if(character == '9')
            character = '+';
        else if(character == '+')
            character = '/';
        else{
            character += 1;
        }
        value += 1;
    }

    table_in.insert({character, value});
}