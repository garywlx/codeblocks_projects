#ifndef FOO_H
#define FOO_H

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::sort;

class Foo {
public:
    Foo sorted()&&;
    Foo sorted() const&;

private:
    vector<int> data;
};

#endif // FOO_H
