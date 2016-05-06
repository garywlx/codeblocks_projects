#include <stdio.h>

using namespace std;

union Student
{
    int i;
    unsigned char ch[2];
};

int main()
{
    Student student;
    student.i=0x1420;
    printf("%d %d",student.ch[0],student.ch[1]);
    return 0;
}
