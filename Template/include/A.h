#ifndef A_H
#define A_H

#include <list>
#include <vector>
#include <map>
#include <utility>

//不同名字空间的前置声明方式

namespace test1
{
class C;
}

namespace test2
{
//用using避免使用完全限定名
using test1::C;

class A
{
public:
    C   useC(C);
    C& doToC(C &c)
    {
        //c.print();
    }
    C& doToC2(C& c)
    {
        return doToC(c);
    };

private:
    std::list<C>    _list;
    std::vector<C>  _vector;
    std::map<C, C>  _map;
    C*              _pc;
    C&              _rc;

};
}
#endif // A_H
