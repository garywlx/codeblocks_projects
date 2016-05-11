#ifndef DELETEDEBUG_H
#define DELETEDEBUG_H

#include <iostream>

class DeleteDebug
{
public:
    //DeleteDebug(std::ostream &o=std::cout):os(o),a(10){}
    DeleteDebug()=default;
    template<typename T>void operator()(T *p)const
    {
        std::cerr << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:

};

#endif // DELETEDEBUG_H
