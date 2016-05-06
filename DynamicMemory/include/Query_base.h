#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include<string>

#include "QueryResult.h"
#include "TextQuery.h"

using std::string;

class Query_base
{
    friend class Query;
    public:
        //Query_base();
    protected:
        using line_no=int;
        virtual ~Query_base()=default;
    private:
        virtual QueryResult eval(const TextQuery&)const=0;
        virtual string rep()const =0;
};

#endif // QUERY_BASE_H
