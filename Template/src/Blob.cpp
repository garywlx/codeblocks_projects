#include "Blob.h"

template<typename T>
Blob<T>::Blob():data(std::make_shared<std::vector<T>>())
{
    //ctor
}
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il))
{
    //ctor
}
//通过迭代器初始化
template<typename T>
template <typename It>Blob<T>::Blob(It b,It e)
    :data(std::make_shared<std::vector<T>>(b,e)){}

template<typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob<T>!");
    data->pop_back();
}
template<typename T>
T& Blob<T>::front()
{
    check(0,"front on empty Blob<T>!");
    return data->front();
}
template<typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i,"subscript out of range");
    return (*data)[i];
}
template<typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob<T>!");
    return data->back();
}
template<typename T>
T& Blob<T>::front()const
{
    check(0,"front on empty Blob<T>!");
    return data->front();
}
template<typename T>
T& Blob<T>::back()const
{
    check(0,"back on empty Blob<T>!");
    return data->back();
}
template<typename T>
void Blob<T>::check(size_type i,const string &msg)const
{
    if(i>=data->size())
    {
        throw std::out_of_range(msg);
    }
}
template<typename T>
T Blob<T>::begin()
{
    return Blob<T>(*this);
}
template<typename T>
T Blob<T>::end()
{
    return Blob<T>(*this, data->size());
}
template<typename T>
Blob<T>::~Blob<T>()
{
    //dtor
}
