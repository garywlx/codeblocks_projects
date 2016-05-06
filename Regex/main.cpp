#include <iostream>
#include <fstream>
#include <regex>

using namespace std;
/*
void TestRegex()
{
    string pattern="[^c]ei";
    pattern ="[[:alpha:]]*" +pattern + "[[:alpha:]]*";
    regex r;
    try{
        r.assign(pattern);
    }catch(regex_error e){
        cout << e.what() << "\ncode" << e.code() <<endl;
    }

    smatch results;
    string test_str="receipts friends theif receive";
    if(regex_search(test_str,results,r)){
        cout << results.str() <<endl;
    }
}
*/
int i=1;
int main()
{
    //int i=i;

    cout << showbase;
    cout << "default " << 20 << " " << 1024 << endl;
    cout << "in hex " << hex << 20 << " " << 1024 << endl;
    cout << "in octal " << oct << 20 << " " << 1024 << endl;
    cout << noshowbase;
    return 0;
}
