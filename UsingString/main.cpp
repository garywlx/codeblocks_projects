#include <iostream>       // std::cout
#include <string>
#include <vector>
#include <cstddef>

using namespace std;

vector<string> Split(string &str,string dim)
{
    vector<string> strinarray;
    size_t last = str.find_first_of(dim);
    while (last!=string::npos)
    {
        str.erase(last,1);
        size_t now=str.find_first_of(dim,last);
        string s;
        if(now==string::npos){
            s=str.substr(last,string::npos);
        }else{
            s=str.substr(last,now-last-1);
        }
        last=now;
        if(!s.empty())
            strinarray.push_back(s);
    }
    return strinarray;

}
void Combnatin(string s,int number,string result)
{
    if(number==0){
        if(!result.empty())
            cout << result << endl;
        return;
    }
    result.push_back(s[0]);
    if(s.size()>0)
        Combnatin(s.substr(1),number-1,result);
    result.pop_back();
    if(s.size()>0)
        Combnatin(s.substr(1),number,result);
}
int main ()
{
    /**
    string str ("/Please/sentence/aaaa.txt");
    string str2("abcdefg");
    str2.replace(str2.begin()+1,str2.end()-1,3,'0');
    cout << str2 << endl;
    size_t fileNameIndex=str.find_last_of("/");
    string fileName=str.substr(fileNameIndex+1);
    cout << "fileName:" << fileName << endl;
    string dim="/";

    vector<string> strArray=Split(str,dim);

    cout << "strArray.size:" <<strArray.size() <<endl;
    for(auto tt : strArray)
        cout << tt <<endl;
    float m=3.14;
    //string sm=to_string(m);
    string cm("abcdef"),result;
    Combnatin(cm,3,result);
    */
    string s;
    char arr[3]="Àî";
    int a1=arr[0],a2=arr[1];

    cout << a1 << " "<< a2 << endl;
    //cin >> s;
    //for(auto &ch:s){
    //    cout << ch << endl;
    //}

    return 0;
}
