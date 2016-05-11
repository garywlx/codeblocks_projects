#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <string>
#include <memory>
#include "BlobPtr.h"

using namespace std;

//ǰ������:one-to-one
template <typename> class BlobPtr;
//template <typename> class Blob;

template <typename T>
bool operator==(const Blob<T>&,const Blob<T>&);

template<typename T>
class Blob
{
    friend class BlobPtr<T>;//BlobPtr �� Blob ��ͬ���͵�ʵ��Ϊ��Ԫ
    template <typename X> friend class BlobPtr;//BlobPtr��ÿ��ʵ����Blobÿ��ʵ������Ԫ
    friend class BlobPtr<string>;//BlobPtr<string>ΪBlobÿ��ʵ������Ԫ
    friend bool operator==(const Blob<T>&,const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(initializer_list<T> il);
    template <typename It>Blob(It b,It e);
    size_type size()const{return data->size();}
    bool empty()const{return data->empty();}
    void push_back(const T &t){data->push_back(t);}
    void pop_back();
    T& front();
    T& front()const;
    T& back();
    T& back()const;
    T begin();
    T end();
    T& operator[](size_type i);
    virtual ~Blob();

protected:

private:
    shared_ptr<vector<T>> data;
    void check(size_type i,const string &msg)const;
};

template <typename T>
bool operator==(const Blob<T> &lhs,const Blob<T> &rhs)
{
    return lhs==rhs;
}

#endif // BLOB_H
