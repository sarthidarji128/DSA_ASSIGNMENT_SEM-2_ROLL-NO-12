#include <iostream>
#include <string>

using namespace std;

void PassByByValue(int num2)
{
    cout << "You are in PassByValue()" << endl;
    num2++;
}

class Person
{
    int age;
    string name;
    int height;
    int weight;

public:
    Person() {}
    Person(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setAge(int age)
    {
        this->age = age;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
    void setWeight(int weight)
    {
        this->weight = weight;
    }

    ~Person() {}

    static string Modify_Person(Person); // Declare the function here
};

// Define the function outside the class
string Person::Modify_Person(Person example)
{
    example.setName("Jessica");
    return example.getName();
}

void PassByRef(int &num3)
{
    cout << "You are in PassByRef()" << endl;
    num3 = 50;
    cout << "inside PassByRef() pNum is: " << num3 << endl;
}

int main()
{
    int num1;
    int *pNum;

    num1 = 3;
    *pNum = 5;

    PassByByValue(num1);
    cout << "num1= " << num1 << endl;

    PassByRef(*pNum);
    cout << "outside PassByRef() in main() pNum is: " << pNum << endl;

    PassByByValue(*pNum);

    double *DblePtr;
    DblePtr = new double;
    *DblePtr = 12.0;
    cout << "DblePtr: " << &DblePtr;
    delete[] DblePtr;
    cout << "DblePtr: " << &DblePtr;

    Person human;
    human.setName("Kate");
    human.setAge(27);
    human.setHeight(100);
    human.setWeight(100);

    human.Modify_Person(human);

    cout << "Modify_Person returns: " << human.Modify_Person(human) << endl;

    cout << "name should be Jessica: " << human.getName() << endl;

    return 0;
}
