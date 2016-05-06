#include "AddQuery.h"
#include <algorithm>

using namespace std;

QueryResult AddQuery::eval(const TextQuery &t)const
{
    auto right=rhs.eval(t),left=lhs.eval(t);
    auto ret_lines=make_shared<set<line_no>>();
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),
                     inserter(*ret_lines,ret_lines->begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
}
