#include <iostream>
#include <VECTOR>
#include <LIST>
#include <DEQUE>
#include <STRING>
using namespace std;
int main(){
	string s1("hello");
	vector<string> svec(20,s1);
	list<int> ilist;
	//deque<Sales_Item> items;
	list<string> slist(svec.begin(),svec.end());
	vector<string>::iterator mid=svec.begin() + svec.size()/2;
	deque<string> front(svec.begin(),mid);
	deque<string> back(mid,svec.end());
	char *words[]={"stately", "plump", "buck", "mulligan"};
	size_t words_size=sizeof(words)/sizeof(char*);
	list<string> words2(words,words+words_size);

}