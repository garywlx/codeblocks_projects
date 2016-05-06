#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "StrBlob.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

void testStrBlob()
{
    const StrBlob csb{"hello", "world", "pezy"};
    StrBlob sb{"hello", "world", "Mooophy"};
    StrBlobPtr p(sb);
    //*p="ok";
    StrBlobPtr q=p+1;
    cout << (*q).size() <<endl;
    cout << q->size() <<endl;
    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "pezy";
    std::cout << sb.front() << " " << sb.back() << std::endl;

}
vector<int> *GenericVec()
{
    return new vector<int>;
}
void readVec(vector<int> *p)
{
    int i;
    while (std::cin >> i && i != 999) p->push_back(i);
}
void printVec(vector<int> *p)
{
    //int val;
    for(auto val:*p)
        cout << val << endl;
}


shared_ptr<vector<int>> GenericVec1()
{
    return make_shared<vector<int>>();
}
void readVec(shared_ptr<vector<int>> &p)
{
    int i;
    while (std::cin >> i && i != 999) p->push_back(i);
}
void printVec(shared_ptr<vector<int>> &sp_v)
{
    //int val;
    for(auto val:*sp_v)
        cout << val << endl;
}
void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}
char *catstr(const char *first,const char *second)
{
    int len=strlen(first)+strlen(second);
    char *tmp=new char[len+1];
    strncpy(tmp,first,strlen(first));
    strncpy(tmp+strlen(first),second,strlen(second));
    cout << "char * connect" << endl;
    return tmp;
}
char *catstr(const string first,const string second)
{
    int len=first.size()+second.size();
    char *tmp=new char[len+1];
    memset(tmp,0,len);
    strncpy(tmp,first.c_str(),first.size());
    strncpy(tmp+first.size(),second.c_str(),second.size());
    cout << "string connect" <<endl;
    return tmp;
}
void print(QueryResult &result)
{
    result.print();
}
void runQuery(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if(!(cin>>s)||s=="q")break;
        print(tq.query(s));
    }
}
class strlencmp
{
    size_t sz;
public:
    strlencmp(size_t _sz):sz(_sz){}
    bool operator()(const string &s){
        return s.size()==sz;
    }
};

int main()
{
    //cout << "Hello world!" << endl;
    testStrBlob();
    /**
    shared_ptr<vector<int>> spVec=GenericVec1();
    shared_ptr<vector<int>> spVec2(spVec);
    readVec(spVec);
    printVec(spVec);
    cout << "use count:" <<spVec2.use_count() << endl;
    //delete pVec;


    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p));
    //process(std::shared_ptr<int>(p.get()));
    std::cout << p.use_count() << "\n";
    auto q = p;
    std::cout << p.use_count() << "\n";
    char *a="hello",*b="world";
    cout << catstr(string(a),string(b)) << endl;
    cout << "how long do you want the string? ";
    int size{0};
    cin >>size;
    char* input = new char[size + 1]();
    std::cin.ignore();
    std::cout << "input the string: ";
    std::cin.get(input, size + 1);
    std::cout << input;
    delete[] input;
    */
    ifstream file("out.txt",ios::in);
    runQuery(file);
    /**
    string line,word;
    int a[21]={0};
    while(getline(file,line))
    {
        istringstream record(line);

        while(record >>word){
            for(int i=1;i<=20;i++)
            {
                strlencmp cmp(i);
                if(cmp(word)){
                    a[i]++;
                }
            }

        }
    }
    for(int i=1;i<=20;i++)
        cout << a[i] <<ends;
    cout <<endl;
    */
    return 0;
}
