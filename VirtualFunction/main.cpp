#include <iostream>

using namespace std;
class A
{
    public:virtual void p()
    {
        cout << "A" << endl;
    }
};
class B:public A
{
    public: void t()
    {
        cout << "B" << endl;
    }
};
class C:public B
{
    public: void p()
    {
        cout << "C" << endl;
    }
};
int main()
{
    //cout << "Hello world!" << endl;
    A *a=new A;
    A *b=new B;
    B *c=new C;
    a->p();
    b->p();
    c->p();
    delete a;
    delete b;
    delete c;
    return 0;
}
