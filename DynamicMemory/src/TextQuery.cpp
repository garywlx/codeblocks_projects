#include "TextQuery.h"

TextQuery::TextQuery()
{
    //ctor
}
TextQuery::TextQuery(ifstream &infile):sp_lines(make_shared<vector<string>>())
{
    string line,word;
    int lineNum=0;
    while(getline(infile,line))
    {
        sp_lines->push_back(line);
        istringstream record(line);
        while(record >> word)
        {
            if(word_map.find(word)==word_map.end())
            {
                shared_ptr<set<int>> sp_set=make_shared<set<int>>();
                sp_set->insert(lineNum);
                word_map.insert({word,sp_set});
            }
            else
            {
                word_map[word]->insert(lineNum);
            }
        }
        lineNum++;
    }
}
QueryResult &TextQuery::query(const string &s)const
{
    shared_ptr<set<int>> sp_set=make_shared<set<int>>();
    if(word_map.find(s)!=word_map.end())
    {
        auto t=word_map.find(s);
        sp_set=(*t).second;
    }
    QueryResult *result=new QueryResult(sp_lines,sp_set);
    return *result;
}
TextQuery::~TextQuery()
{
    //dtor
}
