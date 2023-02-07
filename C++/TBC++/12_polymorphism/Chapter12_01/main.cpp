#include <iostream>
#include <string>
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

    virtual void speak() const //* 중요
    {
        cout << m_name << " ??? " << endl;
    }
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

class Dog : public Animal
{
public:
    Dog(string name)
        :Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};
int main() {
    Cat cats[] = {Cat("cat1"), Cat("cat2") , Cat("cat3"), Cat("cat4")};
    Dog dogs[] = {Dog("dog1"), Dog("Dog2")};

//    for (int i=0; i<4; ++i)
//        cats[i].speak();
//
//    for (int i=0; i<2; ++i)
//        dogs[i].speak();

    Animal *my_animals[] = {&cats[0], &cats[1], &cats[2], &cats[3],
                            &dogs[0], &dogs[1]};

    for(int i=0; i<6; ++i)
        my_animals[i]->speak();

//    Animal animal("my animal");
//    Cat cat("my cat");
//    Dog dog("my dog");
//
//    animal.speak();
//    cat.speak();
//    dog.speak();
//
//    Animal *ptr_animal1 = &cat;
//    Animal *ptr_animal2 = &dog;
//
//    ptr_animal1->speak();
//    ptr_animal2->speak();

    return 0;
}
