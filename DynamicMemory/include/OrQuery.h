#ifndef ORQUERY_H
#define ORQUERY_H

#include <BinaryQuery.h>


class OrQuery : public BinaryQuery
{
    friend Query operator&(const Query &left,const Query &right);
    //public:
    OrQuery(const Query &l,const Query &r):BinaryQuery(l,r,"|"){}
    QueryResult eval(const TextQuery &t)const;

};
inline Query operator&(const Query &left,const Query &right)
{
    return shared_ptr<Query_base>(new OrQuery(left,right));
}
#endif // ORQUERY_H
