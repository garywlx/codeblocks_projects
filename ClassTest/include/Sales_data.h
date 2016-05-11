#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;
class Sales_data
{
    public:
        Sales_data();
        void print(string &s){
             cout << "Print " << s << " use general member function!" <<endl;
        }
        static int static_print(string &s)
        {
            cout << "Print " << s << " use static member function!" <<endl;
            return 1;
        }
        static string ss;
        virtual ~Sales_data();

    protected:
    private:
        string s;
};

#endif // SALES_DATA_H
