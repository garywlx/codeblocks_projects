#include <iostream>
#include <string>
#include<string.h>
#include <vector>
using namespace std;

int split(string path,vector<string> &v_path){

  char str[100];
  strcpy(str,path.c_str());
  char * pch;
  pch = strtok (str,"/");
  while (pch != NULL)
  {
    v_path.push_back(string(pch));
    pch = strtok (NULL, "/");
  }
  return 0;

}
int main()
{
    string pa,pb,rp;
    vector<string> pathArrayA,pathArrayB;

    cin >> pa >> pb;

    split(pa,pathArrayA);
    split(pb,pathArrayB);
    vector<string>::iterator itA=pathArrayA.begin();
    vector<string>::iterator itB=pathArrayB.begin();
    for(;itA!=pathArrayA.end()&&itB!=pathArrayB.end();itA++,itB++){
        if(*itA!=*itB)
            break;
    }
    itA++;
    while(itA!=pathArrayA.end()){
        rp.append("../");
        itA++;
    }
    while(itB!=pathArrayB.end()){
        rp.append(*itB + "/");
        itB++;
    }
    rp.erase(rp.end()-1);
    cout << rp << endl;
    return 0;
}
