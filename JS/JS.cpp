// JS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fun.h"
#include<IOSTREAM>
#include<STRING>

using namespace std;

size_t count_calls(){
	static size_t ctr=0;
	return ctr++;
}
inline const string &shorterString(const string &s1,const string &s2){
	return s1.size() > s2.size() ? s1:s2;
}
int main(int argc, char* argv[])
{
	string s1("liquanxin");
	string s2("Hello");
	cout << shorterString(s1,s2) << endl;
	for(size_t i=0;i!=10;i++)
		cout << count_calls() << endl;
	return 0;
}
