#include <iostream>
#include<string>
#include <vector>
#include <bitset>

using namespace std;

#define LEFTSHIT(x) (x<<1)|1

int findLeft1(unsigned int x)
{
    int pos=0;
    while(((x&1)==0)&&(pos<8*sizeof(int)))
    {
        x=x>>1;
        pos++;
    }
    return pos;

}
int findRight1(unsigned int x)
{
    int pos=31;
    while(((x&0x80000000)!=0x80000000)&&(pos>=0))
    {
        x=x<<1;
        pos--;
    }
    return pos;
}
vector<int> findPostionOf1(unsigned int x)
{
    vector<int> result;
    //int a[31]={0};
    bitset<32> bits(x);
    for(int i=0;i<bits.size();i++)
    {
        if(bits.test(i)){
            result.push_back(i);
        }
    }
    return result;
}
/** \brief 打印字符串所有子集
     *
     * \param
     * \param
     * \return
     *
     */
void TestFindSubSequence(string s)
{
    unsigned int target=0,start=1;
    for(int i=0; i<s.size(); i++)
        target=LEFTSHIT(target);
    while(start<=target)
    {
        //int left=findLeft1(start);
        //int right=findRight1(start);
        vector<int> bitPositions=findPostionOf1(start);
        //cout <<"start: " << start << " left: " << left << " right: " << right<< endl;
        string ss;
        for(auto pos:bitPositions){
            ss.push_back(s[pos]);
        }
        //string ss=s.substr(left,right-left+1);
        cout << ss <<endl;
        start++;
    }
}
 /** \brief 打印字符串所有字串

     *
     * \param
     * \param
     * \return
     *
     */
void TestFindSubString(string s)
{
    for(int len=1;len<=s.size();len++){
        int start=0;
        while(start+len<=s.size()){
            string sub=s.substr(start,len);
            cout << sub << endl;
            start++;
        }
    }

}
int main()
{
    cout << "Input a string:" << endl;
    string s;
    cin >> s;
    bitset<32> bits;
    cin >> bits;
    unsigned int t=bits.to_ulong();
    cout << t << endl;
    //s.assign(bits.to_string());
    //cout << s << endl;
    return 0;
}
