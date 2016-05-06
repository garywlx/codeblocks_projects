#include "QueryResult.h"

QueryResult::QueryResult()
{
    //ctor
}
void QueryResult::print()
{
    int size=sp_set->size();
    cout << "Elements occurs " << size << " times" <<endl;
    for(auto set_it=sp_set->begin();set_it!=sp_set->end();set_it++)
    {
        string line =sp_lines->at(*set_it);
        cout << "(line " << (*set_it+1) << ") " << line <<endl;
    }
}
QueryResult::~QueryResult()
{
    //dtor
}
