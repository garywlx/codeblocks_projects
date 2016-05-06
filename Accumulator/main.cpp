#include <iostream>
#include "Temp.h"

using namespace std;
/** \brief
 *  step1:add two numbner igore carry bits
    step2:calculate carry bit
    step3:calculate carry bit and firtst sum until don't produce new carry bit.
 *
 * \param
 * \param
 * \return
 *
 */

int add(int num1,int num2)
{
    int sum,carry;
    do
    {
        sum=num1^num2;
        carry=(num1&num2)<<1;
        num1=sum;
        num2=carry;
    }while(num2!=0);
    return num1;
}
int main()
{
    /**
    int n;
    cin >> n;
    Temp::Reset();
    Temp *a=new Temp[n];
    delete []a;
    a=NULL;
    unsigned int sum=Temp::GetSum();
    cout << sum <<endl;
    */
    int m,n;
    cin >> m>>n;
    cout << add(m,n)<< endl;
    return 0;
}
