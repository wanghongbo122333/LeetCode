#include <iostream>
#include <vector>
using namespace std;
// global variable
int g_int = 0;
class Base
{
private:
    int a = 0;

public:
    Base();
    virtual ~Base();
};

Base::Base()
{
    cout << "Base class construct" << endl;
}
Base::~Base()
{
    cout << "Base class destroyed" << endl;
    g_int++;
}

class Derived : public Base
{
private:
    /* data */
public:
    Derived();
    virtual ~Derived();
};

Derived::Derived()
{
    cout << "Derived class construct" << endl;
}

Derived::~Derived()
{
    cout << "Derived class destroyed" << endl;
    g_int++;
}

class CA
{
public:
    CA(){};
    virtual ~CA(){};

private:
    // int m_iTime;

public:
    int GetTime() { return 0; };
    int SetTime(int Time) { return 0; };
};
int main()
{
    // Base *p = new Derived();
    // delete p;
    /*~Base() 不是虚函数的情况，只调用父类的析构函数*/

    Base *p = new Derived();
    cout << "size of Base: " << sizeof(p) << endl;
    delete p;

    CA ca;
    cout << "sizeOf CA: " << sizeof(ca) << endl;
    /* ~Base()是虚函数的话，先调用子类的析构函数，再调用父类的析构函数*/
    return 0;
}