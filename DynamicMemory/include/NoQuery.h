#ifndef NOQUERY_H
#define NOQUERY_H

#include <Query_base.h>
#include "Query.h"

class NoQuery : public Query_base
{
    friend Query operator~(const Query &);
    NoQuery(const Query &q):query(q){}
    QueryResult eval(const TextQuery &t)const;
    string rep()const
    {
        return "~(" + query.rep() + ")";
    }
    Query query;

};
inline Query operator~(const Query &q)
{
    return shared_ptr<Query_base>(new NoQuery(q));
}
#endif // NOQUERY_H
