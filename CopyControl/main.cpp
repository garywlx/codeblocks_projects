#include <iostream>
#include "ex13_05.h"
#include "StrVec.h"
#include "String.h"
#include <vector>
#include "Foo.h"

using namespace std;

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}

int main()
{
    cout << "Hello world!" << endl;

    StrVec m_strvec;
    m_strvec={"louis","tom","jack"};
    m_strvec[1]="asdfasdfa";
    for(auto ss:m_strvec)
        cout << ss << ends;
    cout << endl;
    cout << m_strvec[1] << endl;
    /**
    m_strvec.reverse();
    for(auto ss:m_strvec)
        cout << ss << ends;
    cout << endl;
    m_strvec.resize(3);
    for(auto ss:m_strvec)
        cout << ss << ends;
    cout << endl;
    //HasPtr trans("first"),accum("second");
    //swap(trans,accum);
    //trans=accum;

    vector<String> vec;
    char a[20],b[20];
    cin >> a >> b;
    String sa(a),sb(b),sc,se(sb),sd(std::move(sb)),sf;
    sf=sa;
    sc=std::move(sa);
    cout << "sa.size:"<< sc.size() << endl;
    cout << "sb.size:"<< sf.size() << endl;
    vec.push_back(std::move(sc));
    vec.push_back(std::move(sc));
    Foo().sorted(); // call "&&"
    Foo f;
    f.sorted(); // call "const &"

    String s1("tomcat"),s2("tomcat");
    std::cout << (s1==s2) << endl;
    */
    return 0;
}
