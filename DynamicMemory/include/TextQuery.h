#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>
#include <cstring>
#include "QueryResult.h"

using namespace std;
class TextQuery
{
    public:
        TextQuery();
        TextQuery(ifstream &infile);
        QueryResult& query(const string &s)const;
        virtual ~TextQuery();

    protected:

    private:
        ifstream __file;
        shared_ptr<vector<string>> sp_lines;
        map<string,shared_ptr<set<int>>> word_map;
};

#endif // TEXTQUERY_H
