#include <iostream>
#include <map>
#include <ctype.h>
#include <string.h>
using namespace std;
void m_toLower(char *p){
    while(*p!='\0'){
        *p=tolower(*p);
        p++;
    }

}
void removeSpace(char *p,int n){
    int i,j;
    for(i=0,j=0;j<n;j++)
    {
        if(p[j]!='_'){
            p[i]=p[j];
            i++;
        }
    }
    p[i]='\0';
}
int strEqual(char *p,char *q)
{
    map<char,int> map_p;
    map<char,int> map_q;
    while(*p!='\0'){
        map_p[*p]++;
        p++;
    }
    while(*q!='\0'){
        map_q[*q]++;
        q++;
    }
    int flag=1;
    map<char,int>::iterator map_p_it=map_p.begin();
    map<char,int>::iterator map_q_it=map_q.begin();
    while(map_p_it!=map_p.end()&&map_q_it!=map_q.end()){
        if(map_p_it->first==map_q_it->first&&map_p_it->second==map_q_it->second)
        {
            map_p_it++;
            map_q_it++;
            continue;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==1){
        if(map_p_it==map_p.end()&&map_q_it==map_q.end())
            flag=1;
        else
            flag=0;
    }
    return flag;
}
int main()
{
    char p[100],q[100];
    while(cin >> p >> q)
    {
        removeSpace(p,strlen(p));
        removeSpace(q,strlen(q));
        m_toLower(p);
        m_toLower(q);
        if(strcmp(p,q)==0){
            cout << "No" << endl;
            //return 0;
        }
        else if(strEqual(p,q)==1){
            cout << "Yes" << endl;
            //return 0;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}
