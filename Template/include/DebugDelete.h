#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

/**
 * @brief The DebugDelete class is a deleter functor using delete
 */
class DebugDelete
{
public:
    DebugDelete()=default;
    template<typename T>
    void operator() (T* p) const
    {
        std::cerr << "deleting ptr" << std::endl;
        delete p;
    }

private:
};
#endif // DEBUGDELETE_H
