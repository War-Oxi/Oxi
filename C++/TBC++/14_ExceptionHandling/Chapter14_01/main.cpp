#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

int findFirstChar(const char * string, char ch)
{
    for(std::size_t index = 0; index < strlen(string); ++index)
        if(string[index] == ch)
            return index;

    return -1; //no match
}

double divide(int x, int y, bool &success)
{
    if(y==0)
    {
        success = false;
        return 0.0;
    }
    success = false;
    return static_cast<double>(x) /y;
}

int main() {
//    bool success;
//    double result = divide(5, 3, success);
//
//    if(!success)
//        std::cerr << "An error occurred" << std::endl;
//    else
//        std::cout << "Result is " << result << std::endl;
//
//    std::ifstream input_file("temp.txt");
//    if(!input_file)
//        std::cerr << "Cannot open file" << std::endl;
//    double x;
//    cin >> x;

    try
    {
        throw std::string("My error message ");
    }
    catch(int x)
    {
        cout << "Catch integer " << x << endl;
    }
    catch(double x)
    {
        cout << "Catch double " << x << endl;
    }
    catch(const char * error_message)
    {
        cout << "Char * " << error_message << endl;
    }
    catch(std::string error_message)
    {
        cout << error_message << endl;
    }
    return 0;
}