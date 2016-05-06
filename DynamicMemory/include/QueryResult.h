#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>

using namespace std;

class QueryResult
{
    public:
        QueryResult();
        QueryResult(const string &s,shared_ptr<set<int>> sets,shared_ptr<vector<string>> lines):sp_lines(lines),sp_set(sets){}
        QueryResult(shared_ptr<vector<string>> lines,shared_ptr<set<int>> sets):sp_lines(lines),sp_set(sets){}
        void print();
        const set<int>::iterator begin(){return sp_set->begin();}
        const set<int>::iterator end(){return sp_set->end();}
        shared_ptr<vector<string>> &get_file(){return sp_lines;}
        virtual ~QueryResult();

    protected:

    private:
        shared_ptr<vector<string>> sp_lines;
        shared_ptr<set<int>> sp_set;
    //ifstream __file;
};

#endif // QUERYRESULT_H
