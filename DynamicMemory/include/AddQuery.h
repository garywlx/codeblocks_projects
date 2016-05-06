#ifndef ADDQUERY_H
#define ADDQUERY_H

#include <BinaryQuery.h>


class AddQuery : public BinaryQuery
{
    friend Query operator&(const Query &left,const Query &right);
    //public:
    AddQuery(const Query &l,const Query &r):BinaryQuery(l,r,"&"){}
    QueryResult eval(const TextQuery &t)const;

};
inline Query operator&(const Query &left,const Query &right)
{
    return shared_ptr<Query_base>(new AddQuery(left,right));
}
#endif // ADDQUERY_H
