#include<iostream>
#include<fstream>
#include<string>
using namespace std;
typedef struct point{
    double x;
    double y;
}Point;

Point getPointFromline(char* buffer);
int main()
{
    Point p;
    cout << "Open file:" << endl;
    ifstream file;
    char buffer[256];
    file.open("C:\\raw_dataset\\dataset1.txt");
    if (file.is_open()) {
        while(!file.eof()){
            file.getline(buffer,100);
            cout << buffer << endl;
        }
        file.close();
    }
    return 0;
}
Point getPointFromline(char* buffer){
    Point p;
}
