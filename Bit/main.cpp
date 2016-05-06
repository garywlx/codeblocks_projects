#include <iostream>
#include <fstream>
#include <string>
#include<ctime>
#include<stdlib.h>

using namespace std;

#define SET_VALUE(x,i) (x = (0x80000000>>i) | x)

int main()
{
    cout << "Hello world!" << endl;
    ifstream in1("D:/test/ip.dat",ios::binary);
    ifstream in2("D:/test/ip.dat",ios::binary);
    time_t btime=time(0);
    unsigned data;
    //while(in1.read((char*)(&data),sizeof(unsigned))){};
    in1.close();
    time_t etime=time(0);
    //cout << etime - btime <<endl;
    unsigned data1[1024];
    int ttt;
    while(in2.read((char*)(data1),sizeof(unsigned)*1024)){};
    in2.close();
    time_t etime2=time(0);
    cout << etime2- etime <<endl;
    return 0;
}
