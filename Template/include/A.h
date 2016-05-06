#ifndef A_H
#define A_H

#include <list>
#include <vector>
#include <map>
#include <utility>

//��ͬ���ֿռ��ǰ��������ʽ

namespace test1
{
class C;
}

namespace test2
{
//��using����ʹ����ȫ�޶���
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
