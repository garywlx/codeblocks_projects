#include <iostream>

using namespace std;

class FriendlyClass{
public:
    FriendlyClass()=default;
    FriendlyClass(int x):_x(x){}
    void print(){}
    ~FriendlyClass(){}
private:
    int _x;
};

class Base{
public:
    friend class FriendlyClass;
    friend void FriendlyClass::print();
    Base()=default;
    Base(int x):_x(x){}
    virtual void f1(){
        cout <<"Base virtual f1()" <<endl;
    }
    void f2(){
        cout <<"Base real f2()" <<endl;
    }
    virtual ~Base(){}
private:
    int _x;
};

class Derive:public Base
{
public:
    Derive(int x,int y):Base(x){}
    Derive(int x):Base(x){}
    void f1(){
        cout <<"Derive virtual f1()" <<endl;
    }
    void f2(){
        cout <<"Derive real f2()" <<endl;
    }
    virtual void f3(){
        cout <<"Derive real f3()" <<endl;
    }
     ~Derive(){}
private:
    int x,y;
};
template <typename T> class MakeSealed
{
    friend T;
private:
    MakeSealed()=default;
    ~MakeSealed(){}
};
class SealedClass2:virtual public MakeSealed<SealedClass2>
{
public:
    SealedClass2()=default;
    ~SealedClass2(){}
};
int main()
{
    cout << "Hello world!" << endl;
    Base *p1=new Derive(1);
    Base b;
    p1->f1();
    p1->f2();
    return 0;
}
