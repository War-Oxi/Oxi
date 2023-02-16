#include <iostream>
using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {}

public:
    string getName() { return m_name; }

    virtual void speak() const = 0; //pure virtual function 부모클래스에 구현할 필요 없다. 단 자식클래스에는 반드시 구현하라.

};

class Cat : public Animal
{
public:
    Cat(string name)
        :Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
        :Animal(std::move(name))
    {}

    virtual void speak() const
    {
        cout << m_name << " Moooo " << endl;
    }
};

int main()
{
    Cow cow("hello");
    cow.speak();

    return 0;
}
