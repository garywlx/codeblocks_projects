#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include <iostream>
#include <functional>
#include "DebugDelete.h"

template<typename T>
class shared_pointer;

namespace cp5
{
    template<typename T>
    void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs)
    {
        using std::swap;
        swap(lhs.data, rhs.data);
        swap(lhs.use_number, rhs.use_number);
        swap(lhs.deleter, rhs.deleter);
    }
}


template<typename T>
class shared_pointer
{
public:
    //Construction function
    shared_pointer():data(nullptr),use_number(new size_t(0)),deleter(DeleteDebug()) {}
    explicit shared_pointer (T* p,std::function<void(T*)> d = DebugDelete()):
        data(p),use_number(new size_t(1)),deleter(d) {}
    //! copy constructor.
    //! increment useCount for each Copy
    shared_pointer(const shared_pointer& sp):
        data(sp.data), use_number(sp.use_number), deleter(sp.deleter)
    {
        ++*use_number;
    }
    //! move constructor
    shared_pointer (shared_pointer<T>&& sp) noexcept;
    //! copy assginment
    shared_pointer& operator=(const shared_pointer<T>& sp) noexcept;
    //! move assginment
    shared_pointer& operator=(const shared_pointer<T>&& sp) noexcept;
    //reset
    void reset() noexcept{decrement_and_destroy();}
    void swap(shared_pointer& rhs)
    {
        cp5::swap(*this, rhs);
    }
    void reset (T* sp)
    {
        if (data != sp)
        {
            decrement_and_destroy();
            data = sp;
            use_number = new std::size_t(1);
        }
    }

    //void swap (shared_pointer& x) noexcept;
    T* get() const noexcept
    {
        return data;
    }
    T& operator*() const noexcept
    {
        return *data;
    }
    T* operator->() const noexcept
    {
        return &*data;
    }
    long int use_count() const noexcept
    {
        return *use_number;
    }
    bool unique() const noexcept
    {
        return *use_number==1;
    }
    virtual ~shared_pointer() {decrement_and_destroy();}

protected:

private:
    T* data;
    size_t* use_number;
    std::function<void(T*)> deleter;
    void decrement_and_destroy()
    {
        if (data && 0 == --*use_number)
            delete use_number,
                   deleter(data);
        else if (!data)
            delete use_number;
        use_number = nullptr;
        data = nullptr;
    }
};

//! move constructor
template<typename T>
inline
shared_pointer<T>::shared_pointer(shared_pointer&& sp) noexcept:
    data(sp.data), use_number(sp.use_number), deleter(std::move(sp.deleter))
{
    sp.data = nullptr;
    sp.use_number = nullptr;
}

//! copy assginment
template<typename T>
inline
shared_pointer<T>& shared_pointer<T>::operator=(const shared_pointer<T>& sp) noexcept
{
    ++*use_number;
    decrement_and_destroy();
    data=sp.data;
    use_number=sp.use_number;
    deleter=sp.deleter;
    return *this;
}
//! move assginment
template<typename T>
inline
shared_pointer<T>& shared_pointer<T>::operator=(const shared_pointer<T>&& sp) noexcept
{
    swap(*this, sp);
    sp.decrement_and_destroy();
    return *this;
}

#endif // SHARED_POINTER_H
