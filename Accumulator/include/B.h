#ifndef B_H
#define B_H

#include <A.h>


class B : public A
{
    public:
        B();
        virtual unsigned int Sum(unsigned int n);
        virtual ~B();

    protected:

    private:
};

#endif // B_H
